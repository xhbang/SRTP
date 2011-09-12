<%@ page contentType="text/html; charset=gb2312" language="java"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>电子信息平台</title>
	<link rel=stylesheet type=text/css href="../lib/bbs.css">
	<jsp:useBean scope="page" id="Board" class="com.Board" />
	</head>
	<%
		String sBoardID = request.getParameter("BoardID");
		long lBoardID = Long.parseLong(sBoardID);
		Board.setBoardID(lBoardID);
		Board.init();
	%>
	<body>
	<div align="center">
	<br>
	<form name="form1" method="post" action="modify_board_save.jsp" target="_self">
	<input type="hidden" name="BoardID" value="<%=lBoardID%>">
	<p>
	讨论区名称：<input type="text" name="BoardName" value="<%=Board.getBoardName()%>">
	</p>
	<p>
	<input type="submit" value="修改" name="sub">&nbsp;&nbsp;
	<input type="reset" value="重填" name="res">
	</p>
	</form>
	</div>
	</body>
</html>
