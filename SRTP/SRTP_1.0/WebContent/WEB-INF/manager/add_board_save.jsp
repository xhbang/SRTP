<%@ page contentType="text/html; charset=gb2312" language="java"%>
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
	request.setCharacterEncoding("gb2312");
	String sBoardName=request.getParameter("BoardName");
	//将讨论区信息保存到数据库中
	Board.setBoardName(sBoardName);
	if(!Board.exist())
	{
		if(Board.add())
		{
			out.println("<p><font color=blue>添加讨论区成功</font></p>");
			out.println("<input type=button name=btn value=\"回到讨论区管理\" onClick='window.location=\"./board_management.jsp\"'>");
		}
		else
		{
			out.println("<p><font color=red>添加讨论区失败，请重试</font></p>");
			out.println("<input type=button name=btn value=\"返回\" onClick='window.history.go(-1)'>");
		}
	}
	else
	{
			out.println("<p>讨论区&nbsp;<font color=red>"+sBoardName+"</font>&nbsp;已经存在</p>");
			out.println("<input type=button name=btn value=\"返回\" onClick='window.history.go(-1)'>");
	}
%>
	</div>
	</body>
</html>
