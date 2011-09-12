<%@ page contentType="text/html; charset=gb2312" language="java" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="../lib/bbs.css">
		<jsp:useBean scope="page" id="Board" class="com.Board" />

	</head>
	<body>
	<div align="center"><br>
<%
	//获取所要删除的讨论区信息索引号
	String[] sBoardID = request.getParameterValues("DeleteID");	
	//将所有索引号组织成一个字符串
	String sDeleteBoardID = "0";
	if (sBoardID != null)
	{
		for(int i=0;i<sBoardID.length;i++)
		{
			sDeleteBoardID = sDeleteBoardID +"," + sBoardID[i];	
		}		
	}

	//删除讨论区
	if(Board.delete(sDeleteBoardID))
	{
		out.println("<p><font color=blue>讨论区删除成功</font></p>");
		out.println("<p><a href=\"board_management.jsp\" target=\"_self\"><font color=blue>返回讨论区管理</font></a></p>");
	}
	else
	{
		out.println("<p><font color=red>讨论区删除失败，请重试</font></p>");
		out.println("<div><input type=\"button\" name=\"btn\" value=\"返回\" onClick=\"javascript:window.history.go(-1)\"></div>");
	}
%>
	</div>
	</body>
</html>
