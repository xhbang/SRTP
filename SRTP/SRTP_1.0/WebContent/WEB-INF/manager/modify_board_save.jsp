<%@ page contentType="text/html; charset=gb2312" language="java"%>
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
			request.setCharacterEncoding("gb2312");
			String sBoardID = request.getParameter("BoardID");
			long lBoardID = Long.parseLong(sBoardID);
			Board.setBoardID(lBoardID);
			String sBoardName=request.getParameter("BoardName");
			//��������Ϣ���浽���ݿ���
			Board.setBoardName(sBoardName);
			if(!Board.exist())
			{
				if(Board.modify())
				{
					out.println("<p><font color=blue>�޸��������ɹ�</font></p>");
					out.println("<input type=button name=btn value=\"�ص�����������\" onClick='window.location=\"./board_management.jsp\"'>");
				}
				else
				{
					out.println("<p><font color=red>�޸�������ʧ�ܣ�������</font></p>");
					out.println("<input type=button name=btn value=\"����\" onClick='window.history.go(-1)'>");
				}
			}
			else
			{
					out.println("<p>������&nbsp;<font color=red>"+sBoardName+"</font>&nbsp;�Ѿ�����</p>");
					out.println("<input type=button name=btn value=\"����\" onClick='window.history.go(-1)'>");
			}
	%>
	</div>
	</body>
</html>
