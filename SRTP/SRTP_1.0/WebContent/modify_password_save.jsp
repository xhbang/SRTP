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
	//获取session中保存的UserName
	String sUserName = (String) session.getAttribute("UserName");
	User.setUserName(sUserName);
	//获取session中保存的UserID
	long lUserID = (Long) session.getAttribute("UserID");	
	User.setUserID(lUserID);
	//获取所填写的旧密码
	String sOldUserPassword = request.getParameter("OldUserPassword");	
	User.setUserPassword(sOldUserPassword);
	//判断用户填写的旧密码是否正确
	if(User.valid())
	{
		//修改用户密码
		String sUserPassword = request.getParameter("UserPassword");
		User.setUserPassword(sUserPassword);	
		if(User.modify_UserPassword())
		{
			out.println("<p><font color=blue>修改用户密码成功</font></p>");
		out.println("<p><a href=\"info_management.jsp\" target=\"_self\"><font color=blue>返回资料管理</font></a></p>");

		}
		else
		{
			out.println("<p><font color=red>修改用户密码失败，请稍后重试</font></p>");
			out.println("<input type=button name=btn value=返回 onClick='window.history.go(-1)'>");
		}
	}
	else
	{
		out.println("<p><font color=red>您输入的旧密码错误</font></p>");
		out.println("<input type=button name=btn value=返回 onClick='window.history.go(-1)'>");
	}
%>
	</div>
	</body>
</html>
