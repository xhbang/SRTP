<%@ page contentType="text/html; charset=gb2312" language="java"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>电子信息平台</title>
	<link rel=stylesheet type=text/css href="./lib/bbs.css">
	<jsp:useBean scope="page" id="Board" class="com.Board" />
	<jsp:useBean scope="page" id="Article" class="com.Article" />
	<jsp:useBean scope="page" id="User" class="com.User" />
	<%
		//获取当前访问用户信息，并判断他是否是登录用户
		String sUserName = (String) session.getAttribute("UserName");
		//获取当前登录用户的索引号
		long lUserID = (Long) session.getAttribute("UserID");
		//获取当前讨论区的索引号，并转为长整型
		String sBoardID = request.getParameter("BoardID");
		long lBoardID = Long.parseLong(sBoardID);
		Board.setBoardID(lBoardID);
		Board.init();
		//判断是否是回复文章，如果是回复文章，则获取所要回复文章的标题和部分内容 
		String sArticleID = request.getParameter("ArticleID");	
		long lArticleID = Long.parseLong(sArticleID);
		
		String sTitle = "";
		String sContent = "";
		if(lArticleID != 0)
		{		
			Article.setArticleID(lArticleID);
			Article.init();
			sTitle="回复："+Article.getTitle();	
			
			User.setUserID(Article.getUserID());
			User.init();				
			sContent=Article.getContent();
			if(sContent.length()>100)
			{
				sContent = sContent.substring(1,100);
				sContent = sContent + "………………";
			}
			sContent = "【 在 "+User.getUserName()+" 的文章中提到: 】\r\n" + sContent;
			sContent = "\r\n\r\n\r\n\r\n----------------------------------------------------------\r\n" + sContent;
	
			if(Article.getFatherID()!=0)
			{
				lArticleID = Article.getFatherID();
			}
		}	
	%>

	</head>
	<body>
	<div align="center">
	<br>
	<form name="form1" method="post" action="add_article_save.jsp" target="_self" enctype="multipart/form-data">
	<input type="hidden" name="BoardID" value="<%=lBoardID%>">
	<input type="hidden" name="FatherID" value="<%=lArticleID%>">
	<table width="450" border="1" cellpadding="0" cellspacing="0" bordercolor="#E1E1E1">
	<tr>
		<td width="100%"height="25" align="left">&nbsp;标题：<input type="text" name="Title" size="40" value="<%=sTitle%>"></td>
	</tr>
	<tr>
		<td width="100%"height="25" align="left">&nbsp;作者：<font color="#0000FF"><%=sUserName%></font></td>
	</tr>
	<tr>
		<td width="100%"height="25" align="left">&nbsp;讨论区：<font color="#0000FF"><%=Board.getBoardName()%></font></td>
	</tr>
	<tr>
		<td width="100%" align="center" valign="top">
		<textarea name="Content" rows="16" cols="60"><%=sContent%>
		</textarea>
		</td>
	</tr>
		<tr>
		<td width="100%" align="left" height="40">
		&nbsp;上传图片：<input type="file" name="Pic" size="40"><br>
		&nbsp;<font color="#FF0000">注意：</font>只能上传bmp、gif、jpg格式的图片，大小不能超过1.5MB
		</td>
	</tr>
	</table>
	<p>
	<input type="submit" value="发表" name="sub">&nbsp;&nbsp;
	<input type="reset" value="清除" name="res">
	</p>
	</form>
	</div>
	</body>
</html>
