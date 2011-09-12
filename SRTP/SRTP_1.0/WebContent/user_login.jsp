<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>电子信息平台</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
<jsp:useBean scope="page" id="User" class="com.User" />
</head>
<%
	//获取登录信息
	String sUserName = request.getParameter("UserName");
	String sUserPassword = request.getParameter("UserPassword");
	
	//判断登录信息是否正确
	User.setUserName(sUserName);
	User.setUserPassword(sUserPassword);	
	if(!User.valid())
	{
		out.println("<h3 align=center><font color=red>您输入的用户名或者密码有误</font></h3>");
		out.println("<div align=\"center\"><input type=\"button\" name=\"btn\" value=\"返回\" onClick=\"javascript:window.history.go(-1)\"></div>");
	}
	else
	{
		//将用户名、用户ID、用户角色等信息保存到session中
		session.setAttribute("UserName",User.getUserName());
		session.setAttribute("UserID",User.getUserID());
		session.setAttribute("Role",User.getRole());
		
		//判断用户角色，根据结果跳转到相应页面
		if(User.getRole().equals("0"))
			response.sendRedirect("./main.jsp");
		else
			response.sendRedirect("./manager/main.jsp");
}
%>