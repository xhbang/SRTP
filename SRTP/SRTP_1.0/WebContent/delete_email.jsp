<%@ page contentType="text/html; charset=gb2312" language="java" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Email" class="com.Email" />

	</head>
	<body>
	<div align="center"><br>
<%
	//获取所要删除的邮件索引号，并将它们转换成一个字符串
	String[] sEmailID = request.getParameterValues("DeleteID");	
	String sDeleteEmailID = "0";
	if (sEmailID != null)
	{
		for(int i=0;i<sEmailID.length;i++)
		{
			sDeleteEmailID = sDeleteEmailID +"," + sEmailID[i];	
		}		
	}

	//删除邮件
	if(Email.delete(sDeleteEmailID))
	{
		out.println("<p><font color=blue>邮件删除成功</font></p>");
		out.println("<p><a href=\"email_management.jsp\" target=\"_self\"><font color=blue>返回邮件管理</font></a></p>");
	}
	else
	{
		out.println("<p><font color=red>邮件删除失败，请重试</font></p>");
		out.println("<div><input type=\"button\" name=\"btn\" value=\"返回\" onClick=\"javascript:window.history.go(-1)\"></div>");
	}
%>
	</div>
	</body>
</html>
