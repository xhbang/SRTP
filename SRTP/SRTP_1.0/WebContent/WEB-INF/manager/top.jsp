<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%
	String sUserName = (String) session.getAttribute("UserName");

%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ϣƽ̨</title>
<link rel=stylesheet type=text/css href="../lib/bbs.css">
<jsp:useBean scope="page" id="User" class="com.User" />
</head>
<body bgcolor="#F5F5F5">
<div align="center">
<br>
<h1>������Ϣƽ̨</h1>
<table width="90%">
<tr>
<td height="30" align="center"><a href="./board_management.jsp" target="mainFrame"><font color="#666666"><b>����������</b></font></a></td>
<td height="30" align="center"><a href="../email_management.jsp" target="mainFrame"><font color="#666666"><b>�ʼ�����</b></font></a></td>
<td height="30" align="center"><a href="../info_management.jsp" target="mainFrame"><font color="#666666"><b>���Ϲ���</b></font></a></td>
<td height="30" align="center"><font color="#666666"><b>��ӭ����</b></font><font color="#0000FF"><%=sUserName%></font></td>
<td height="30" align="center"><a href="../logout.jsp" target="_top"><font color="#666666"><b>�˳�</b></font></a></td>
</tr>
</table>
</div>
</body>
</html>
