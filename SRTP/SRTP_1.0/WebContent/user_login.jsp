<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ϣƽ̨</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
<jsp:useBean scope="page" id="User" class="com.User" />
</head>
<%
	//��ȡ��¼��Ϣ
	String sUserName = request.getParameter("UserName");
	String sUserPassword = request.getParameter("UserPassword");
	
	//�жϵ�¼��Ϣ�Ƿ���ȷ
	User.setUserName(sUserName);
	User.setUserPassword(sUserPassword);	
	if(!User.valid())
	{
		out.println("<h3 align=center><font color=red>��������û���������������</font></h3>");
		out.println("<div align=\"center\"><input type=\"button\" name=\"btn\" value=\"����\" onClick=\"javascript:window.history.go(-1)\"></div>");
	}
	else
	{
		//���û������û�ID���û���ɫ����Ϣ���浽session��
		session.setAttribute("UserName",User.getUserName());
		session.setAttribute("UserID",User.getUserID());
		session.setAttribute("Role",User.getRole());
		
		//�ж��û���ɫ�����ݽ����ת����Ӧҳ��
		if(User.getRole().equals("0"))
			response.sendRedirect("./main.jsp");
		else
			response.sendRedirect("./manager/main.jsp");
}
%>