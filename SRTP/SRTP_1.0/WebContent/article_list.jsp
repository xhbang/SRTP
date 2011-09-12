<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<%@ page import="java.util.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>电子信息平台</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Article" class="com.Article" />
		<jsp:useBean scope="page" id="Board" class="com.Board" />
		<jsp:useBean scope="page" id="Page" class="com.SplitPage" />
		<jsp:useBean scope="page" id="User" class="com.User" />

		<%
			//获取讨论区索引号
			String sBoardID = request.getParameter("BoardID");
			long lBoardID = Long.parseLong(sBoardID);
			//初始化讨论区信息
			Board.setBoardID(lBoardID);
			Board.init();
			//获取当前讨论区中的所有主题文章信息
			Article.setBoardID(lBoardID);
			ResultSet rs = Article.show_board_articles();
			//初始化分页显示类，每页显示10条记录
			Page.initialize(rs,10);
			//获取当前所要显示的页数
			String strPage=null;
			int showPage = 1;
			//获取跳转到的目的页面
			strPage=request.getParameter("showPage");	
			if (strPage==null)
				showPage=1;
			else
			{
				try
				{
					showPage=Integer.parseInt(strPage);
				}
				catch(NumberFormatException e)
				{
					showPage = 1;
				}
				if(showPage<1) 
					showPage=1;
		
				if(showPage>Page.getPageCount()) 
					showPage=Page.getPageCount();
			}
			
			//获取要显示的数据集合
			Vector vData=Page.getPage(showPage);	
		%>
	</head>
	<body>
	<div align="center"><br>
	<h3>讨论区：<font color="#0000FF"><%=Board.getBoardName()%></font></h3>
	<table width="100%" border="0" cellpadding="0" cellspacing="2">
		<tr bgcolor="#F5F5F5">
		<th width="15%" height="30" align="center">作者</th>
		<th width="20%" height="30" align="center">发布时间</th>
		<th width="45%" height="30" align="center">文章标题</th>
		<th width="10%" height="30" align="center">阅读数</th>
		<th width="10%" height="30" align="center">回复数</th>
		</tr>
	<%
		for(int i=0;i<vData.size();i++)
		{ 
			//循环显示文章信息
			String[] sData=(String[])vData.get(i);
			long lUserID = Long.parseLong(sData[2]);
			User.setUserID(lUserID);
			if(User.init())
			{
	%>
			<tr>
				<td height="25" align="center"><font color="#0000FF"><%=User.getUserName()%></font></td> 
				<td height="25" align="center"><%=sData[5]%></td>
				<td height="25" align="left"><a href="article_detail.jsp?ArticleID=<%=sData[0]%>&BoardID=<%=sBoardID%>" target="_self"><font color="#0000FF"><%="&nbsp;"+sData[1]%></font></a></td> 	
				<td height="25" align="center"><font color="#FF0000"><%=sData[3]%></font></td> 
				<td height="25" align="center"><font color="#FF0000"><%=sData[4]%></font></td> 
			</tr> 		
	<%
			}
		}
	%>
	</table>
	<p>
	<form action="article_list.jsp" method="post" target="_self">	
		[<a href="./add_article_form.jsp?BoardID=<%=lBoardID%>&ArticleID=0" target="_self"><font color="#0000FF">发表文章</font></a>]&nbsp;
		第<font color="#FF0000"><%=showPage%></font>页/共<font color=red><%=Page.getPageCount()%></font>页&nbsp;
		<a href="article_list.jsp?showPage=1" target="_self"><font color="#0000FF">[首页]</font></a>&nbsp;			
		<%
			//判断"上一页"链接是否要显示
			if(showPage > 1)
			{				
		%>
				<a href="article_list.jsp?showPage=<%=showPage-1%>&BoardID=<%=lBoardID%>" target="_self"><font color="#0000FF">[上一页]</font> </a>&nbsp;
		<%
			}
			else
				out.println("[上一页]&nbsp;");

			//判断"下一页"链接是否要显示
			if(showPage < Page.getPageCount())
			{				
		%>
				<a href="article_list.jsp?showPage=<%=showPage+1%>&BoardID=<%=lBoardID%>" target="_self"><font color="#0000FF">[下一页]</font> </a>&nbsp;
		<%
			}
			else
				out.println("[下一页]&nbsp;");

		%> 
		<a href="article_list.jsp?showPage=<%=Page.getPageCount()%>&BoardID=<%=lBoardID%>" target="_self"><font color="#0000FF">[尾页]</font> </a>&nbsp;
		转到
		<select name="showPage">
		<%
			for(int x=1;x<=Page.getPageCount();x++)
			{
		%>
				<option value="<%=x%>" <%if(showPage==x) out.println("selected");%> ><%=x%></option>
		<%
			}
		%>
		</select>
		<input type="hidden" name="BoardID" value="<%=lBoardID%>">页&nbsp;
		<input type="submit" name="go" value="提交"/>
	</form></p>
	<%rs.close();%>
	</div>
	</body>
</html>

