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
	<div align="center">
<%
	//��ȡ��ǰ�û����û���
	String sUserName = (String) session.getAttribute("UserName");

	//�����Ҫ��ʾ�ʼ���������
	String sID = request.getParameter("EmailID");
	long lEmailID = Long.parseLong(sID);

	//����ʼ���Ϣ
	Email.setEmailID(lEmailID);
	Email.init();

	//�жϵ�ǰ�û��Ƿ���Ȩ�쿴���ʼ�
	if(Email.getReceiver().compareTo(sUserName) != 0 && Email.getSender().compareTo(sUserName) != 0)
	{
		out.println("<p align=center>��ûȨ�鿴���ʼ���</p>");
		out.println("<div align=\"center\"><input type=\"button\" name=\"btn\" value=\"����\" onClick=\"javascript:window.history.go(-1)\"></div>");
		return;
	}
%>

	<br>
	<table width="400" border="1" cellpadding="0" cellspacing="0">
	<tr>
	<td align="left">
	�����ˣ�<font color="#0000FF"><%=Email.getSender()%></font><br>
	�����ˣ�<font color="#0000FF"><%=Email.getReceiver()%></font><br>
	��&nbsp;&nbsp;�⣺<%=Email.getSubject()%><br><br>
	<%
		//�滻�ʼ������еĻس��ͻ��з��ţ��Ա���ҳ������������ʾ
		String sContent = Email.getContent();
		sContent = sContent.replaceAll("\r\n","<br>");
		out.println(sContent+"<br>");
	%>
	<br>
	</table>
	<p>
	[<a href="send_email_form.jsp?ArticleID=0&EmailID=<%=lEmailID%>" target="_self"><font color="#0000FF">�ظ�</font></a>]&nbsp;&nbsp;&nbsp;&nbsp;
	[<a href="javascript:window.history.go(-1)" target="_self"><font color="#0000FF">����</font></a>]
	</p>
	</div>
	<%
		//���ʼ��������Ѷ�
		Email.update_tag();
	%>
	</body>
</html>
