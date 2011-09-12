<%@ page contentType="text/html; charset=gb2312" language="java" %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>电子信息平台</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
<jsp:useBean scope="page" id="Email" class="com.Email" />
<jsp:useBean scope="page" id="Article" class="com.Article" />
<jsp:useBean scope="page" id="User" class="com.User" />
</head>
<%
	//获取当前用户的用户名
	String sUserName = (String) session.getAttribute("UserName");
	String sSubject = "";
	String sContent = "";
	String sReceiver = "";
	//获得索要回复的邮件的索引号，并将它转化为长整型	
	String sEmailID = request.getParameter("EmailID");
	long lEmailID = Long.parseLong(sEmailID);

	//判断是否是回复邮件，如果是的话则获取邮件信息
	if(lEmailID != 0)
	{
		Email.setEmailID(lEmailID);
		Email.init();
		sSubject = "回复："+Email.getSubject();		
		sReceiver = Email.getSender();
		sContent = Email.getContent();
		if(sContent.length()>100)
		{
			sContent = sContent.substring(1,100);
			sContent = sContent + "………………";
		}
		sContent = "【 在 "+sReceiver+" 的来信中提到: 】\r\n" + sContent;
		sContent = "\r\n\r\n\r\n\r\n----------------------------------------------------------\r\n" + sContent;
	}
	//获取所要回信的文章的索引号，并将它转化为长整型
	String sArticleID = request.getParameter("ArticleID");
	long lArticleID = Long.parseLong(sArticleID);

	//判断是否是回信文章，如果是的话则获取文章信息
	if(lArticleID != 0)
	{
		Article.setArticleID(lArticleID);
		Article.init();		
		sSubject = "回复："+Article.getTitle();		
		User.setUserID(Article.getUserID());
		User.init();
		sReceiver = User.getUserName();
		sContent = Article.getContent();				
		if(sContent.length()>100)
		{
			sContent = sContent.substring(1,100);
			sContent = sContent + "………………";
		}
		sContent = "【 在 "+sReceiver+" 的文章中提到: 】\r\n" + sContent;
		sContent = "\r\n\r\n\r\n\r\n----------------------------------------------------------\r\n" + sContent;
	}
%>
<body>
<div align="center">
<br>
<form name="form1" method="post" action="send_email_save.jsp" target="_self">
<table width="400" border="0" cellpadding="0" cellspacing="1">
<tr>
<td align="left">
发信人：<font color="#0000FF"><%=sUserName%></font><br>
标&nbsp;&nbsp;题: <input type="text" name="Subject" size="50" value="<%=sSubject%>"> <br>
收信人：<input type="text" name="Receiver" value="<%=sReceiver%>">&nbsp;&nbsp; <br>
<textarea name="Content" rows="16" cols="60"><%=sContent%>
</textarea>
<p align="center">
<input type="submit" value="发送" name="sub">
&nbsp;&nbsp;
<input type="reset" value="重写" name="res">
</p>
</table>
</form>
</div>
</body>
</html>
