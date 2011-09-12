<%@ page contentType="text/html; charset=gb2312" language="java"  %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="User" class="com.User" />

	</head>
	<body>
		<div align="center"><br>

<%
	//设置编码格式
	request.setCharacterEncoding("gb2312");
	//获取session中保存的UserName
	String sUserName = (String) session.getAttribute("UserName");
	//获取session中保存的UserID
	long lUserID = (Long) session.getAttribute("UserID");	
	User.setUserID(lUserID);

	//获取修改后的用户信息
	String sNickName = request.getParameter("NickName");
	String sSex = request.getParameter("Sex");
	String sEmail = request.getParameter("Email");
	//保存用户信息
	User.setNickName(sNickName);
	User.setSex(sSex);
	User.setEmail(sEmail);
	if(User.modify_info())
	{
		out.println("<p><font color=blue>修改用户信息成功</font></p>");
		out.println("<p><a href=\"info_management.jsp\" target=\"_self\"><font color=blue>返回资料管理</font></a></p>");
	}
	else
	{
		out.println("<p><font color=red>修改用户信息失败，请稍后重试</font></p>");
		out.println("<div><input type=button name=btn value=返回 onClick='window.history.go(-1)'></div>");
	}
%>
	</div>
	</body>
</html>
