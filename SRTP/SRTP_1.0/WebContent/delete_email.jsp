<%@ page contentType="text/html; charset=gb2312" language="java" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Email" class="com.Email" />

	</head>
	<body>
	<div align="center"><br>
<%
	//��ȡ��Ҫɾ�����ʼ������ţ���������ת����һ���ַ���
	String[] sEmailID = request.getParameterValues("DeleteID");	
	String sDeleteEmailID = "0";
	if (sEmailID != null)
	{
		for(int i=0;i<sEmailID.length;i++)
		{
			sDeleteEmailID = sDeleteEmailID +"," + sEmailID[i];	
		}		
	}

	//ɾ���ʼ�
	if(Email.delete(sDeleteEmailID))
	{
		out.println("<p><font color=blue>�ʼ�ɾ���ɹ�</font></p>");
		out.println("<p><a href=\"email_management.jsp\" target=\"_self\"><font color=blue>�����ʼ�����</font></a></p>");
	}
	else
	{
		out.println("<p><font color=red>�ʼ�ɾ��ʧ�ܣ�������</font></p>");
		out.println("<div><input type=\"button\" name=\"btn\" value=\"����\" onClick=\"javascript:window.history.go(-1)\"></div>");
	}
%>
	</div>
	</body>
</html>
