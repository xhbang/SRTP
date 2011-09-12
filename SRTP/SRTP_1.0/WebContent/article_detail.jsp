<%@ page contentType="text/html; charset=gb2312" language="java" %>
<%@ page import="java.sql.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Board" class="com.Board" />
		<jsp:useBean scope="page" id="Article" class="com.Article" />
		<jsp:useBean scope="page" id="User" class="com.User" />
<%
	//获得要显示的文章的参数，并将它转为整型值
	String sArticleID = request.getParameter("ArticleID");
	long lArticleID = Long.parseLong(sArticleID);
	
	//获得主题文章信息
	Article.setArticleID(lArticleID);
	Article.init();
	
	//获得作者信息
	User.setUserID(Article.getUserID());
	User.init();
	
	//获得当前讨论区信息
	Board.setBoardID(Article.getBoardID());
	Board.init();	
	
	int count=1;
%>
	</head>
	<body>
	<div align="center"><br>
	<h3>讨论区：<font color="#0000FF"><%=Board.getBoardName()%></font>	</h3>
	<table width="90%" border="1" cellpadding="0" cellspacing="0" bordercolor="#E1E1E1">
	<tr bgcolor="#F5F5F5">
	<td width="95%" height="20" align="left">
	&nbsp;<a href="./add_article_form.jsp?BoardID=<%=Article.getBoardID()%>&ArticleID=<%=Article.getArticleID()%>" target="_self"><font color="#0000FF">[回复文章]</font></a>&nbsp;
	<font color="#0000FF">[本篇作者：<font color="#000000"><%=User.getUserName()+"（"+User.getNickName()+"）"%></font>]</font>&nbsp;
	<a href="./send_email_form.jsp?ArticleID=<%=Article.getArticleID()%>&EmailID=0" target="_self"><font color="#0000FF">[回信给作者]</font></a>&nbsp;
	<a href="./delete_article.jsp?ArticleID=<%=Article.getArticleID()%>&BoardID=<%=Article.getBoardID()%>" target="_self"><font color="#0000FF">[删除文章]</font></a>&nbsp;
	</td>
	<td width="5%" height="20" align="center"><font color="#0000FF"><%=count++%></font></td>
	</tr>
	<tr bgcolor="#FFFFFF">
	<td width="100%" align="left" colspan="2">
	&nbsp;文章标题：<font color="#0000FF"><%=Article.getTitle()%></font><br>
	&nbsp;发文时间：<font color="#0000FF"><%=Article.getCreateTime()%></font><br><br>
	<%
	String sContent = Article.getContent();
	sContent = sContent.replaceAll("\r\n","<br>");
	out.println("&nbsp;"+sContent);
	%>
	<br>
	<%
		//获得当前文章对应图片的保存文件名
		if(Article.getPicUrl().indexOf(".")>-1)
		{
	%>
			<br>&nbsp;附图：<%=Article.getPicName()%><br>
			&nbsp;<img src="./pic/<%=Article.getPicUrl()%>">
	<%
		}
	%>
	</td>
	</tr>
	</table>
	<%
		//将阅读数加1
		int iReadCount = Article.getReadCount()+1;
		Article.setReadCount(iReadCount);
		Article.modify_ReadCount();
		
		//获得当前主题文章的所有回复文章信息
		Article.setFatherID(lArticleID);
		ResultSet rs = Article.show_son_articles();
		while(rs.next())
		{
			//循环显示所有回复文章的信息
			long lUserID = rs.getLong("UserID");
			User.setUserID(lUserID);		
			User.init();
	%>
	<table width="90%" border="1" cellpadding="0" cellspacing="0" bordercolor="#E1E1E1">
		<tr bgcolor="#F5F5F5">
		<td width="95%" height="20" align="left">
		&nbsp;<a href='./add_article_form.jsp?BoardID=<%=Article.getBoardID()%>&ArticleID=<%=rs.getLong("ArticleID")%>' target="_self"><font color="#0000FF">[回复文章]</font></a>&nbsp;
		<font color="#0000FF">[本篇作者：<font color="#000000"><%=User.getUserName()%></font>]</font>&nbsp;
		<a href='./send_email_form.jsp?ArticleID=<%=rs.getLong("ArticleID")%>&EmailID=0' target="_self"><font color="#0000FF">[回信给作者]</font></a>&nbsp;
		<a href='./delete_article.jsp?ArticleID=<%=rs.getLong("ArticleID")%>&BoardID=<%=Article.getBoardID()%>' target="_self"><font color="#0000FF">[删除文章]</font></a>&nbsp;
		</td>
		<td width="5%" height="20" align="center"><font color="#0000FF"><%=count++%></font></td>
		</tr>
		<tr bgcolor="#FFFFFF">
		<td width="100%" align="left" colspan="2">
		文章标题：<%=rs.getString("Title")%><br>
		作者：<%=User.getUserName()+" ("+User.getNickName()+")"%><br>
		发文时间：<%=rs.getString("CreateTime")%><br><br>
		<%
			sContent = rs.getString("Content");
			sContent = sContent.replaceAll("\r\n","<br>");
			out.println(sContent);
		%>
		<br>
		<%
			if(rs.getString("PicUrl").indexOf(".")>-1)
			{
		%>
				<br>附图：<%=rs.getString("PicName")%><br>
				<img src="./pic/<%=rs.getString("PicUrl")%>">
		<%
			}		
		%>
		</td>
		</tr>
	</table>
	<%
		}
	%>
	<br>
	<br>
	</div>
	</body>
</html>
