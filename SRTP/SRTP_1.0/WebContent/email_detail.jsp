<%@ page contentType="text/html; charset=gb2312" language="java" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Email" class="com.Email" />

	</head>
	<body>
	<div align="center">
<%
	//获取当前用户的用户名
	String sUserName = (String) session.getAttribute("UserName");

	//获得索要显示邮件的索引号
	String sID = request.getParameter("EmailID");
	long lEmailID = Long.parseLong(sID);

	//获得邮件信息
	Email.setEmailID(lEmailID);
	Email.init();

	//判断当前用户是否有权察看该邮件
	if(Email.getReceiver().compareTo(sUserName) != 0 && Email.getSender().compareTo(sUserName) != 0)
	{
		out.println("<p align=center>您没权查看该邮件！</p>");
		out.println("<div align=\"center\"><input type=\"button\" name=\"btn\" value=\"返回\" onClick=\"javascript:window.history.go(-1)\"></div>");
		return;
	}
%>

	<br>
	<table width="400" border="1" cellpadding="0" cellspacing="0">
	<tr>
	<td align="left">
	发信人：<font color="#0000FF"><%=Email.getSender()%></font><br>
	收信人：<font color="#0000FF"><%=Email.getReceiver()%></font><br>
	标&nbsp;&nbsp;题：<%=Email.getSubject()%><br><br>
	<%
		//替换邮件内容中的回车和换行符号，以便在页面上能正常显示
		String sContent = Email.getContent();
		sContent = sContent.replaceAll("\r\n","<br>");
		out.println(sContent+"<br>");
	%>
	<br>
	</table>
	<p>
	[<a href="send_email_form.jsp?ArticleID=0&EmailID=<%=lEmailID%>" target="_self"><font color="#0000FF">回复</font></a>]&nbsp;&nbsp;&nbsp;&nbsp;
	[<a href="javascript:window.history.go(-1)" target="_self"><font color="#0000FF">返回</font></a>]
	</p>
	</div>
	<%
		//将邮件设置了已读
		Email.update_tag();
	%>
	</body>
</html>
