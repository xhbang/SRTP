<%@ page contentType="text/html; charset=gb2312" language="java"%>
<%@ page import="java.sql.*"%>
<%@ page import="java.util.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
		<title>������Ϣƽ̨</title>
		<link rel=stylesheet type=text/css href="./lib/bbs.css">
		<jsp:useBean scope="page" id="Article" class="com.Article" />
		<jsp:useBean scope="page" id="Board" class="com.Board" />
		<jsp:useBean scope="page" id="Page" class="com.SplitPage" />
		<jsp:useBean scope="page" id="User" class="com.User" />

		<%
			//��ȡ������������
			String sBoardID = request.getParameter("BoardID");
			long lBoardID = Long.parseLong(sBoardID);
			//��ʼ����������Ϣ
			Board.setBoardID(lBoardID);
			Board.init();
			//��ȡ��ǰ�������е���������������Ϣ
			Article.setBoardID(lBoardID);
			ResultSet rs = Article.show_board_articles();
			//��ʼ����ҳ��ʾ�࣬ÿҳ��ʾ10����¼
			Page.initialize(rs,10);
			//��ȡ��ǰ��Ҫ��ʾ��ҳ��
			String strPage=null;
			int showPage = 1;
			//��ȡ��ת����Ŀ��ҳ��
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
			
			//��ȡҪ��ʾ�����ݼ���
			Vector vData=Page.getPage(showPage);	
		%>
	</head>
	<body>
	<div align="center"><br>
	<h3>��������<font color="#0000FF"><%=Board.getBoardName()%></font></h3>
	<table width="100%" border="0" cellpadding="0" cellspacing="2">
		<tr bgcolor="#F5F5F5">
		<th width="15%" height="30" align="center">����</th>
		<th width="20%" height="30" align="center">����ʱ��</th>
		<th width="45%" height="30" align="center">���±���</th>
		<th width="10%" height="30" align="center">�Ķ���</th>
		<th width="10%" height="30" align="center">�ظ���</th>
		</tr>
	<%
		for(int i=0;i<vData.size();i++)
		{ 
			//ѭ����ʾ������Ϣ
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
		[<a href="./add_article_form.jsp?BoardID=<%=lBoardID%>&ArticleID=0" target="_self"><font color="#0000FF">��������</font></a>]&nbsp;
		��<font color="#FF0000"><%=showPage%></font>ҳ/��<font color=red><%=Page.getPageCount()%></font>ҳ&nbsp;
		<a href="article_list.jsp?showPage=1" target="_self"><font color="#0000FF">[��ҳ]</font></a>&nbsp;			
		<%
			//�ж�"��һҳ"�����Ƿ�Ҫ��ʾ
			if(showPage > 1)
			{				
		%>
				<a href="article_list.jsp?showPage=<%=showPage-1%>&BoardID=<%=lBoardID%>" target="_self"><font color="#0000FF">[��һҳ]</font> </a>&nbsp;
		<%
			}
			else
				out.println("[��һҳ]&nbsp;");

			//�ж�"��һҳ"�����Ƿ�Ҫ��ʾ
			if(showPage < Page.getPageCount())
			{				
		%>
				<a href="article_list.jsp?showPage=<%=showPage+1%>&BoardID=<%=lBoardID%>" target="_self"><font color="#0000FF">[��һҳ]</font> </a>&nbsp;
		<%
			}
			else
				out.println("[��һҳ]&nbsp;");

		%> 
		<a href="article_list.jsp?showPage=<%=Page.getPageCount()%>&BoardID=<%=lBoardID%>" target="_self"><font color="#0000FF">[βҳ]</font> </a>&nbsp;
		ת��
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
		<input type="hidden" name="BoardID" value="<%=lBoardID%>">ҳ&nbsp;
		<input type="submit" name="go" value="�ύ"/>
	</form></p>
	<%rs.close();%>
	</div>
	</body>
</html>
