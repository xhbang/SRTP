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
	<body bgcolor="#F5F5F5">
	<div align="center">
	<h1>������Ϣƽ̨</h1>
	<%
		//�����Ƿ�ע��ɹ��ı���
		boolean isSuc = false;
		//��������ʽ
		request.setCharacterEncoding("gb2312");
		//��ȡ��֤����Ϣ
		String sRand1 = (String)session.getAttribute("Rand");
		String sRand2 = request.getParameter("Rand");	
		//�ж���д����֤���Ƿ���ȷ
		if (sRand1.compareTo(sRand2)==0) 
		{	
			//��ȡ��Ҫע����û���
			String sUserName = request.getParameter("UserName");
			User.setUserName(sUserName);
			//�жϸ��û����Ƿ��Ѿ����� 
			if(User.exist())
				out.println("<p>�û���&nbsp;<font color=red>"+sUserName+"</font>&nbsp;�Ѿ����ڣ�</p>");
			else
			{
				//��ȡ����ע����Ϣ
				String sUserPassword = request.getParameter("UserPassword");
				String sNickName = request.getParameter("NickName");
				String sSex = request.getParameter("Sex");
				String sEmail = request.getParameter("Email");
				User.setUserPassword(sUserPassword);
				User.setNickName(sNickName);
				User.setSex(sSex);
				User.setEmail(sEmail);
				User.setRole("0");
				//����ע����Ϣ
				if(User.add())
				{
					isSuc = true;
					out.println("<p align=center><font color=blue>�û�ע��ɹ�</font></p>");
				}
				else
					out.println("<p><font color=red>�û�ע��ʧ�ܣ����Ժ�����</font></p>");
			}
		} 
		else
			out.println("<p><font color=red>���������֤�����</font></p>");
		
		//�����תĿ��ҳ����Ϣ
		if(isSuc)
			out.println("<p><input type=button name=btn value=\"&nbsp;��¼&nbsp;\" onClick=\"window.location='index.html'\"></p>");
		else
			out.println("<p><input type=button name=btn value=\"&nbsp;����&nbsp;\" onClick='window.history.go(-1)'></p>");
		//�Ƴ���֤����Ϣ
		session.removeAttribute("Rand");
	%>
	</div>
	</body>
</html>
