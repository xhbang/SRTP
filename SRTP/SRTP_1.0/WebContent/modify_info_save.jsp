<%@ page contentType="text/html; charset=gb2312" language="java"  %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="User" class="com.User" />

	</head>
	<body>
		<div align="center"><br>

<%
	//���ñ����ʽ
	request.setCharacterEncoding("gb2312");
	//��ȡsession�б����UserName
	String sUserName = (String) session.getAttribute("UserName");
	//��ȡsession�б����UserID
	long lUserID = (Long) session.getAttribute("UserID");	
	User.setUserID(lUserID);

	//��ȡ�޸ĺ���û���Ϣ
	String sNickName = request.getParameter("NickName");
	String sSex = request.getParameter("Sex");
	String sEmail = request.getParameter("Email");
	//�����û���Ϣ
	User.setNickName(sNickName);
	User.setSex(sSex);
	User.setEmail(sEmail);
	if(User.modify_info())
	{
		out.println("<p><font color=blue>�޸��û���Ϣ�ɹ�</font></p>");
		out.println("<p><a href=\"info_management.jsp\" target=\"_self\"><font color=blue>�������Ϲ���</font></a></p>");
	}
	else
	{
		out.println("<p><font color=red>�޸��û���Ϣʧ�ܣ����Ժ�����</font></p>");
		out.println("<div><input type=button name=btn value=���� onClick='window.history.go(-1)'></div>");
	}
%>
	</div>
	</body>
</html>
