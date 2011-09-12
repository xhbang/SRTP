<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="com.jspsmart.upload.*"%>
<%@ page import="javax.servlet.*" %>
<%@ page import="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
	<jsp:useBean scope="page" id="Article" class="com.Article" />
	</head>
	<body>
	<div align="center"><br>
	<%
		//获取当前用户的索引号
		long lUserID =  (Long) session.getAttribute("UserID");
		try
		{
			//新建一个SmartUpload对象
			SmartUpload su = new SmartUpload();
			//上传初始化
			su.initialize(pageContext);
			//设定上传限制
			//限制上传文件的最大长度。
			su.setMaxFileSize(1500000*8);
			//设定允许上传的文件（通过扩展名限制）
			su.setAllowedFilesList("jpg,gif,bmp,JPG,GIF,BMP");
			//上传文件
			
				su.upload();		
			
			
			//获取文章信息
			String sBoardID=su.getRequest().getParameter("BoardID");
			long lBoardID = Long.parseLong(sBoardID);
			String sFatherID=su.getRequest().getParameter("FatherID");
			long lFatherID = Long.parseLong(sFatherID);
			String sTitle=su.getRequest().getParameter("Title");
			String sContent=su.getRequest().getParameter("Content");
			String sPicName="";
			String sPicUrl="";		
			//判断是否有附件上传
			com.jspsmart.upload.File file = su.getFiles().getFile(0);
			if (!file.isMissing())
			{
				String sPic=file.getFileName();	
				//将附件以 用户索引号+当前时间+附件扩展名 作为文件名保存		
				java.text.SimpleDateFormat dateFormatter = new java.text.SimpleDateFormat("yyyyMMddHHmmss");
				String sNowTime = dateFormatter.format(new java.util.Date());
				sPicUrl = sNowTime+"-"+lUserID+"."+ file.getFileExt();
				sPicName = file.getFileName();
				file.saveAs("/pic/"+sPicUrl);
			}
			//将文章信息保存到数据库中
			Article.setTitle(sTitle);
			Article.setContent(sContent);
			Article.setBoardID(lBoardID);
			Article.setFatherID(lFatherID);
			Article.setUserID(lUserID);
			Article.setPicName(sPicName);
			Article.setPicUrl(sPicUrl);
			if(Article.add())
			{
				out.println("<p><font color=blue>文章发表成功</font></p>");
				out.println("<div><input type=button name=btn value=\"回到讨论区\" onClick='window.location=\"./article_list.jsp?BoardID="+lBoardID+"\"'></div>");
			}
			else
			{
				out.println("<p><font color=red>文章发表失败，请重试</font></p>");
				out.println("<div><input type=button name=btn value=\"返回\" onClick='window.history.go(-1)'></div>");
				return;
			}
			//使所要回复的文章的回复数加1
			Article.setArticleID(lFatherID);
			Article.init();
			//使文章的回复数加1
			int iReCount = Article.getReCount()+1;
			Article.setReCount(iReCount);
			//保存回复数
			Article.modify_ReCount();		
		}
		catch(Exception e)
		{
			out.println("<p><font color=red>您上传的文件格式不对，或者上传文件太大！</font></p>");
			out.println("<div><input type=button name=btn value=返回 onClick='window.history.go(-1)'></div>");
			return;
		}
	%>
	</div>
	</body>
</html>
