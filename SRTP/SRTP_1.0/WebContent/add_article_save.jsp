<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="com.jspsmart.upload.*"%>
<%@ page import="javax.servlet.*" %>
<%@ page import="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
	<jsp:useBean scope="page" id="Article" class="com.Article" />
	</head>
	<body>
	<div align="center"><br>
	<%
		//��ȡ��ǰ�û���������
		long lUserID =  (Long) session.getAttribute("UserID");
		try
		{
			//�½�һ��SmartUpload����
			SmartUpload su = new SmartUpload();
			//�ϴ���ʼ��
			su.initialize(pageContext);
			//�趨�ϴ�����
			//�����ϴ��ļ�����󳤶ȡ�
			su.setMaxFileSize(1500000*8);
			//�趨�����ϴ����ļ���ͨ����չ�����ƣ�
			su.setAllowedFilesList("jpg,gif,bmp,JPG,GIF,BMP");
			//�ϴ��ļ�
			
				su.upload();		
			
			
			//��ȡ������Ϣ
			String sBoardID=su.getRequest().getParameter("BoardID");
			long lBoardID = Long.parseLong(sBoardID);
			String sFatherID=su.getRequest().getParameter("FatherID");
			long lFatherID = Long.parseLong(sFatherID);
			String sTitle=su.getRequest().getParameter("Title");
			String sContent=su.getRequest().getParameter("Content");
			String sPicName="";
			String sPicUrl="";		
			//�ж��Ƿ��и����ϴ�
			com.jspsmart.upload.File file = su.getFiles().getFile(0);
			if (!file.isMissing())
			{
				String sPic=file.getFileName();	
				//�������� �û�������+��ǰʱ��+������չ�� ��Ϊ�ļ�������		
				java.text.SimpleDateFormat dateFormatter = new java.text.SimpleDateFormat("yyyyMMddHHmmss");
				String sNowTime = dateFormatter.format(new java.util.Date());
				sPicUrl = sNowTime+"-"+lUserID+"."+ file.getFileExt();
				sPicName = file.getFileName();
				file.saveAs("/pic/"+sPicUrl);
			}
			//��������Ϣ���浽���ݿ���
			Article.setTitle(sTitle);
			Article.setContent(sContent);
			Article.setBoardID(lBoardID);
			Article.setFatherID(lFatherID);
			Article.setUserID(lUserID);
			Article.setPicName(sPicName);
			Article.setPicUrl(sPicUrl);
			if(Article.add())
			{
				out.println("<p><font color=blue>���·���ɹ�</font></p>");
				out.println("<div><input type=button name=btn value=\"�ص�������\" onClick='window.location=\"./article_list.jsp?BoardID="+lBoardID+"\"'></div>");
			}
			else
			{
				out.println("<p><font color=red>���·���ʧ�ܣ�������</font></p>");
				out.println("<div><input type=button name=btn value=\"����\" onClick='window.history.go(-1)'></div>");
				return;
			}
			//ʹ��Ҫ�ظ������µĻظ�����1
			Article.setArticleID(lFatherID);
			Article.init();
			//ʹ���µĻظ�����1
			int iReCount = Article.getReCount()+1;
			Article.setReCount(iReCount);
			//����ظ���
			Article.modify_ReCount();		
		}
		catch(Exception e)
		{
			out.println("<p><font color=red>���ϴ����ļ���ʽ���ԣ������ϴ��ļ�̫��</font></p>");
			out.println("<div><input type=button name=btn value=���� onClick='window.history.go(-1)'></div>");
			return;
		}
	%>
	</div>
	</body>
</html>
