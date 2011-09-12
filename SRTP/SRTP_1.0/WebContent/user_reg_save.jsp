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
	<body bgcolor="#F5F5F5">
	<div align="center">
	<h1>电子信息平台</h1>
	<%
		//定义是否注册成功的变量
		boolean isSuc = false;
		//定义编码格式
		request.setCharacterEncoding("gb2312");
		//获取验证码信息
		String sRand1 = (String)session.getAttribute("Rand");
		String sRand2 = request.getParameter("Rand");	
		//判断填写的验证码是否正确
		if (sRand1.compareTo(sRand2)==0) 
		{	
			//获取所要注册的用户名
			String sUserName = request.getParameter("UserName");
			User.setUserName(sUserName);
			//判断该用户名是否已经存在 
			if(User.exist())
				out.println("<p>用户名&nbsp;<font color=red>"+sUserName+"</font>&nbsp;已经存在！</p>");
			else
			{
				//获取其他注册信息
				String sUserPassword = request.getParameter("UserPassword");
				String sNickName = request.getParameter("NickName");
				String sSex = request.getParameter("Sex");
				String sEmail = request.getParameter("Email");
				User.setUserPassword(sUserPassword);
				User.setNickName(sNickName);
				User.setSex(sSex);
				User.setEmail(sEmail);
				User.setRole("0");
				//保存注册信息
				if(User.add())
				{
					isSuc = true;
					out.println("<p align=center><font color=blue>用户注册成功</font></p>");
				}
				else
					out.println("<p><font color=red>用户注册失败，请稍后重试</font></p>");
			}
		} 
		else
			out.println("<p><font color=red>您输入的验证码错误</font></p>");
		
		//输出跳转目的页面信息
		if(isSuc)
			out.println("<p><input type=button name=btn value=\"&nbsp;登录&nbsp;\" onClick=\"window.location='index.html'\"></p>");
		else
			out.println("<p><input type=button name=btn value=\"&nbsp;返回&nbsp;\" onClick='window.history.go(-1)'></p>");
		//移除验证码信息
		session.removeAttribute("Rand");
	%>
	</div>
	</body>
</html>
