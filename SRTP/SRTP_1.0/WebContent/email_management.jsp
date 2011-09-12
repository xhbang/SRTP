<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Email" class="com.Email" />
	</head>
	<body>
<%
	//获取当前用户的用户名
	String sUserName = (String) session.getAttribute("UserName");
	Email.setReceiver(sUserName);
	//获取所有邮件信息
	ResultSet rs = Email.rec_list();	
%>

	<div align="center"><br>
	<form name="form1" method="post" action="delete_email.jsp" target="_self">
	<table width="95%" border="0" cellpadding="0" cellspacing="1">
	<tbody>
	<tr bgcolor="#F5F5F5">
		<th width="6%" height="30" align="center">选中</th>
		<th width="6%" height="30" align="center">序号</th>
		<th width="10%" height="30" align="center">状态</th>
		<th width="15%" height="30" align="center">发信人</th>
		<th width="43%" height="30" align="center">标题</th>
		<th width="20%" height="30" align="center">发信时间</th>
	</tr>
<%
	int i=0;
	//循环显示邮件信息
	while(rs.next())
	{
		i++;
	%>
		<tr>
		<td width="6%" height="25" align="center"><input name="DeleteID" type="checkbox" value='<%=rs.getLong("EmailID")%>'></td>
		<td width="6%" height="25" align="center"><%=i%></td>
		<td width="10%" height="25" align="center">
	<%
		int iTag = rs.getInt("Tag");
		if(iTag == 0)
		{
			out.println("<font color=red>未读</font>");
		}
		else
		{
			out.println("<font color=blue>已读</font>");
		}
	%>&nbsp;
		</td>
		<td width="15%" height="25" align="center"><%=rs.getString("Sender")%></td>
		<td width="43%" height="25" align="left">&nbsp;<a href='email_detail.jsp?EmailID=<%=rs.getLong("EmailID")%>' target="_self"><font color="#0000FF"><%=rs.getString("Subject")%></font></a></td>
		<td width="20%" height="25" align="center"><%=rs.getString("CreateTime")%></td>
		</tr>
	<%
	}
	%>
	</tbody>
	</table>
	<p>
	<a href="send_email_form.jsp?ArticleID=0&EmailID=0" target="_self"><font color="#0000FF">[发送新邮件]</font></a>&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="javascript:form1.submit()"><font color="#0000FF">[删除选中邮件]</font></a>&nbsp;&nbsp;&nbsp;&nbsp;
	</p>
	</form>
	</div>
	</body>
</html>
