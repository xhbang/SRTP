<%@ page contentType="text/html; charset=gb2312" language="java"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="../lib/bbs.css">
	<jsp:useBean scope="page" id="Article" class="com.Article" />
	</head>
	<body>
	<div align="center"><br>
	<%
		//��ȡ��Ҫɾ��������������
		String sArticleID = request.getParameter("ArticleID");
		long lArticleID = Long.parseLong(sArticleID);
		Article.setArticleID(lArticleID);
		//��ȡsession�б����UserID������ֵ
		long lUserID = (Long) session.getAttribute("UserID");
		Article.setUserID(lUserID);
		//��ȡsession�б����Role������ֵ
		String sRole =  (String) session.getAttribute("Role");
		
		String sBoardID = request.getParameter("BoardID");
		
		if(sRole.equals("1") || Article.valid())
		{
			if(Article.delete())
			{
				out.println("<p><font color=blue>ɾ�����³ɹ�</font></p>");
				String sURL = "./article_list.jsp?BoardID="+sBoardID;					
				out.println("<input type=button name=btn value=\"���������б�\" onClick='window.location=\""+sURL+"\"'>");
			}
			else
			{
				out.println("<p><font color=red>ɾ������ʧ�ܣ�������</font></p>");
				out.println("<input type=button name=btn value=\"����\" onClick='window.history.go(-1)'>");
			}
		}
		else
		{
				out.println("<p><font color=red>����Ȩɾ����ǰ����</font></p>");
				out.println("<input type=button name=btn value=\"����\" onClick='window.history.go(-1)'>");
		}
	%>
	</div>
	</body>
</html>
