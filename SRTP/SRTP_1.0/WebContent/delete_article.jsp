<%@ page contentType="text/html; charset=gb2312" language="java"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="../lib/bbs.css">
	<jsp:useBean scope="page" id="Article" class="com.Article" />
	</head>
	<body>
	<div align="center"><br>
	<%
		//获取所要删除的文章索引号
		String sArticleID = request.getParameter("ArticleID");
		long lArticleID = Long.parseLong(sArticleID);
		Article.setArticleID(lArticleID);
		//获取session中保存的UserID的属性值
		long lUserID = (Long) session.getAttribute("UserID");
		Article.setUserID(lUserID);
		//获取session中保存的Role的属性值
		String sRole =  (String) session.getAttribute("Role");
		
		String sBoardID = request.getParameter("BoardID");
		
		if(sRole.equals("1") || Article.valid())
		{
			if(Article.delete())
			{
				out.println("<p><font color=blue>删除文章成功</font></p>");
				String sURL = "./article_list.jsp?BoardID="+sBoardID;					
				out.println("<input type=button name=btn value=\"返回文章列表\" onClick='window.location=\""+sURL+"\"'>");
			}
			else
			{
				out.println("<p><font color=red>删除文章失败，请重试</font></p>");
				out.println("<input type=button name=btn value=\"返回\" onClick='window.history.go(-1)'>");
			}
		}
		else
		{
				out.println("<p><font color=red>您无权删除当前文章</font></p>");
				out.println("<input type=button name=btn value=\"返回\" onClick='window.history.go(-1)'>");
		}
	%>
	</div>
	</body>
</html>
