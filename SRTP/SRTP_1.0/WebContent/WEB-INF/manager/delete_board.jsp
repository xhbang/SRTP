<%@ page contentType="text/html; charset=gb2312" language="java" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="../lib/bbs.css">
		<jsp:useBean scope="page" id="Board" class="com.Board" />

	</head>
	<body>
	<div align="center"><br>
<%
	//��ȡ��Ҫɾ������������Ϣ������
	String[] sBoardID = request.getParameterValues("DeleteID");	
	//��������������֯��һ���ַ���
	String sDeleteBoardID = "0";
	if (sBoardID != null)
	{
		for(int i=0;i<sBoardID.length;i++)
		{
			sDeleteBoardID = sDeleteBoardID +"," + sBoardID[i];	
		}		
	}

	//ɾ��������
	if(Board.delete(sDeleteBoardID))
	{
		out.println("<p><font color=blue>������ɾ���ɹ�</font></p>");
		out.println("<p><a href=\"board_management.jsp\" target=\"_self\"><font color=blue>��������������</font></a></p>");
	}
	else
	{
		out.println("<p><font color=red>������ɾ��ʧ�ܣ�������</font></p>");
		out.println("<div><input type=\"button\" name=\"btn\" value=\"����\" onClick=\"javascript:window.history.go(-1)\"></div>");
	}
%>
	</div>
	</body>
</html>
