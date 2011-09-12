<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<jsp:useBean scope="page" id="Board" class="com.Board" />
<jsp:useBean scope="page" id="Article" class="com.Article" />
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="../lib/bbs.css">
	</head>
	<body>
	<div align="center">
	<br><br>
	<form name="form1" action="delete_board.jsp" target="_self" method="post">
	<table width="70%" border="0">
	<tr bgcolor="#F5F5F5">
	<th width="10%" align="center" height="30">选择</th>
	<th width="45%" align="center" height="30">讨论区名称</th>
	<th width="25%" align="center" height="30">主题文章数量</th>
	<th width="20%" align="center" height="30">修改</th>
	</tr>
	<%
		//获得所有讨论区信息
		ResultSet rs = Board.show_all();
		int i = 0;
		while(rs.next())
		{
			//显示各讨论区的详细信息
			Article.setBoardID(rs.getLong("BoardID"));
			i++;
	%>
			<tr>
			<td width="10%" align="center" height="25"><input type="checkbox" name="DeleteID" value='<%=rs.getLong("BoardID")%>'></td>
			<td width="45%" align="center" height="25">
			<a href='../article_list.jsp?BoardID=<%=rs.getLong("BoardID")%>' target="_self"><font color="#0000FF">	<%=rs.getString("BoardName")%></font></a></td>
			<td width="25%" align="center" height="25"><font color="#FF0000"><%=Article.articles_count()%></font></td>
			<td width="20%" align="center" height="25"><a href='modify_board_form.jsp?BoardID=<%=rs.getLong("BoardID")%>' target="_self"><font color="#0000FF">修改</font></a></td>
			</tr>
	<%
		}
	%>	
	</table>
	<p>
	<input type="submit" name="sub" value="删除选中的讨论区">&nbsp;&nbsp;
	<input type="button" name="btn" value="添加新讨论区" onClick="javascript:window.location='add_board_form.jsp'">
	</p>
	</form>
	
	</div>
	</body>
</html>
