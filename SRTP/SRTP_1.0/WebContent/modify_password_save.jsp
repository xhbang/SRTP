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
	//��ȡsession�б����UserName
	String sUserName = (String) session.getAttribute("UserName");
	User.setUserName(sUserName);
	//��ȡsession�б����UserID
	long lUserID = (Long) session.getAttribute("UserID");	
	User.setUserID(lUserID);
	//��ȡ����д�ľ�����
	String sOldUserPassword = request.getParameter("OldUserPassword");	
	User.setUserPassword(sOldUserPassword);
	//�ж��û���д�ľ������Ƿ���ȷ
	if(User.valid())
	{
		//�޸��û�����
		String sUserPassword = request.getParameter("UserPassword");
		User.setUserPassword(sUserPassword);	
		if(User.modify_UserPassword())
		{
			out.println("<p><font color=blue>�޸��û�����ɹ�</font></p>");
		out.println("<p><a href=\"info_management.jsp\" target=\"_self\"><font color=blue>�������Ϲ���</font></a></p>");

		}
		else
		{
			out.println("<p><font color=red>�޸��û�����ʧ�ܣ����Ժ�����</font></p>");
			out.println("<input type=button name=btn value=���� onClick='window.history.go(-1)'>");
		}
	}
	else
	{
		out.println("<p><font color=red>������ľ��������</font></p>");
		out.println("<input type=button name=btn value=���� onClick='window.history.go(-1)'>");
	}
%>
	</div>
	</body>
</html>
