<%@ page contentType="text/html; charset=gb2312" language="java" %>
<%@ page import="java.sql.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Board" class="com.Board" />
		<jsp:useBean scope="page" id="Article" class="com.Article" />
		<jsp:useBean scope="page" id="User" class="com.User" />
<%
	//���Ҫ��ʾ�����µĲ�����������תΪ����ֵ
	String sArticleID = request.getParameter("ArticleID");
	long lArticleID = Long.parseLong(sArticleID);
	
	//�������������Ϣ
	Article.setArticleID(lArticleID);
	Article.init();
	
	//���������Ϣ
	User.setUserID(Article.getUserID());
	User.init();
	
	//��õ�ǰ��������Ϣ
	Board.setBoardID(Article.getBoardID());
	Board.init();	
	
	int count=1;
%>
	</head>
	<body>
	<div align="center"><br>
	<h3>��������<font color="#0000FF"><%=Board.getBoardName()%></font>	</h3>
	<table width="90%" border="1" cellpadding="0" cellspacing="0" bordercolor="#E1E1E1">
	<tr bgcolor="#F5F5F5">
	<td width="95%" height="20" align="left">
	&nbsp;<a href="./add_article_form.jsp?BoardID=<%=Article.getBoardID()%>&ArticleID=<%=Article.getArticleID()%>" target="_self"><font color="#0000FF">[�ظ�����]</font></a>&nbsp;
	<font color="#0000FF">[��ƪ���ߣ�<font color="#000000"><%=User.getUserName()+"��"+User.getNickName()+"��"%></font>]</font>&nbsp;
	<a href="./send_email_form.jsp?ArticleID=<%=Article.getArticleID()%>&EmailID=0" target="_self"><font color="#0000FF">[���Ÿ�����]</font></a>&nbsp;
	<a href="./delete_article.jsp?ArticleID=<%=Article.getArticleID()%>&BoardID=<%=Article.getBoardID()%>" target="_self"><font color="#0000FF">[ɾ������]</font></a>&nbsp;
	</td>
	<td width="5%" height="20" align="center"><font color="#0000FF"><%=count++%></font></td>
	</tr>
	<tr bgcolor="#FFFFFF">
	<td width="100%" align="left" colspan="2">
	&nbsp;���±��⣺<font color="#0000FF"><%=Article.getTitle()%></font><br>
	&nbsp;����ʱ�䣺<font color="#0000FF"><%=Article.getCreateTime()%></font><br><br>
	<%
	String sContent = Article.getContent();
	sContent = sContent.replaceAll("\r\n","<br>");
	out.println("&nbsp;"+sContent);
	%>
	<br>
	<%
		//��õ�ǰ���¶�ӦͼƬ�ı����ļ���
		if(Article.getPicUrl().indexOf(".")>-1)
		{
	%>
			<br>&nbsp;��ͼ��<%=Article.getPicName()%><br>
			&nbsp;<img src="./pic/<%=Article.getPicUrl()%>">
	<%
		}
	%>
	</td>
	</tr>
	</table>
	<%
		//���Ķ�����1
		int iReadCount = Article.getReadCount()+1;
		Article.setReadCount(iReadCount);
		Article.modify_ReadCount();
		
		//��õ�ǰ�������µ����лظ�������Ϣ
		Article.setFatherID(lArticleID);
		ResultSet rs = Article.show_son_articles();
		while(rs.next())
		{
			//ѭ����ʾ���лظ����µ���Ϣ
			long lUserID = rs.getLong("UserID");
			User.setUserID(lUserID);		
			User.init();
	%>
	<table width="90%" border="1" cellpadding="0" cellspacing="0" bordercolor="#E1E1E1">
		<tr bgcolor="#F5F5F5">
		<td width="95%" height="20" align="left">
		&nbsp;<a href='./add_article_form.jsp?BoardID=<%=Article.getBoardID()%>&ArticleID=<%=rs.getLong("ArticleID")%>' target="_self"><font color="#0000FF">[�ظ�����]</font></a>&nbsp;
		<font color="#0000FF">[��ƪ���ߣ�<font color="#000000"><%=User.getUserName()%></font>]</font>&nbsp;
		<a href='./send_email_form.jsp?ArticleID=<%=rs.getLong("ArticleID")%>&EmailID=0' target="_self"><font color="#0000FF">[���Ÿ�����]</font></a>&nbsp;
		<a href='./delete_article.jsp?ArticleID=<%=rs.getLong("ArticleID")%>&BoardID=<%=Article.getBoardID()%>' target="_self"><font color="#0000FF">[ɾ������]</font></a>&nbsp;
		</td>
		<td width="5%" height="20" align="center"><font color="#0000FF"><%=count++%></font></td>
		</tr>
		<tr bgcolor="#FFFFFF">
		<td width="100%" align="left" colspan="2">
		���±��⣺<%=rs.getString("Title")%><br>
		���ߣ�<%=User.getUserName()+" ("+User.getNickName()+")"%><br>
		����ʱ�䣺<%=rs.getString("CreateTime")%><br><br>
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
				<br>��ͼ��<%=rs.getString("PicName")%><br>
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
