<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<jsp:useBean scope="page" id="Board" class="com.Board" />
<jsp:useBean scope="page" id="Article" class="com.Article" />
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
	</head>
	<body>
	<div align="center">
	<br><br>
	<table width="70%" border="0">
	<tr bgcolor="#F5F5F5">
	<th width="70%" align="center" height="30">����������</th>
	<th width="30%" align="center" height="30">������������</th>
	</tr>
	<%
		//���������������Ϣ
		ResultSet rs = Board.show_all();
		while(rs.next())
		{
			//��ʾ������������ϸ��Ϣ
			Article.setBoardID(rs.getLong("BoardID"));
	%>
			<tr>
			<td width="40%" align="center" height="25">
			<a href='article_list.jsp?BoardID=<%=rs.getLong("BoardID")%>' target="_self"><font color="#0000FF">	<%=rs.getString("BoardName")%></font></a></td>
			<td width="20%" align="center" height="25"><font color="#FF0000"><%=Article.articles_count()%></font></td>
			</tr>
	<%
		}
	%>	
	</table>
	</div>
	</body>
</html>
