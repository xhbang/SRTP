<%@ page contentType="text/html; charset=gb2312" language="java"%>
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
		//��ȡ��ǰ�����û���Ϣ�����ж����Ƿ��ǵ�¼�û�
		String sUserName = (String) session.getAttribute("UserName");
		//��ȡ��ǰ��¼�û���������
		long lUserID = (Long) session.getAttribute("UserID");
		//��ȡ��ǰ�������������ţ���תΪ������
		String sBoardID = request.getParameter("BoardID");
		long lBoardID = Long.parseLong(sBoardID);
		Board.setBoardID(lBoardID);
		Board.init();
		//�ж��Ƿ��ǻظ����£�����ǻظ����£����ȡ��Ҫ�ظ����µı���Ͳ������� 
		String sArticleID = request.getParameter("ArticleID");	
		long lArticleID = Long.parseLong(sArticleID);
		
		String sTitle = "";
		String sContent = "";
		if(lArticleID != 0)
		{		
			Article.setArticleID(lArticleID);
			Article.init();
			sTitle="�ظ���"+Article.getTitle();	
			
			User.setUserID(Article.getUserID());
			User.init();				
			sContent=Article.getContent();
			if(sContent.length()>100)
			{
				sContent = sContent.substring(1,100);
				sContent = sContent + "������������";
			}
			sContent = "�� �� "+User.getUserName()+" ���������ᵽ: ��\r\n" + sContent;
			sContent = "\r\n\r\n\r\n\r\n----------------------------------------------------------\r\n" + sContent;
	
			if(Article.getFatherID()!=0)
			{
				lArticleID = Article.getFatherID();
			}
		}	
	%>

	</head>
	<body>
	<div align="center">
	<br>
	<form name="form1" method="post" action="add_article_save.jsp" target="_self" enctype="multipart/form-data">
	<input type="hidden" name="BoardID" value="<%=lBoardID%>">
	<input type="hidden" name="FatherID" value="<%=lArticleID%>">
	<table width="450" border="1" cellpadding="0" cellspacing="0" bordercolor="#E1E1E1">
	<tr>
		<td width="100%"height="25" align="left">&nbsp;���⣺<input type="text" name="Title" size="40" value="<%=sTitle%>"></td>
	</tr>
	<tr>
		<td width="100%"height="25" align="left">&nbsp;���ߣ�<font color="#0000FF"><%=sUserName%></font></td>
	</tr>
	<tr>
		<td width="100%"height="25" align="left">&nbsp;��������<font color="#0000FF"><%=Board.getBoardName()%></font></td>
	</tr>
	<tr>
		<td width="100%" align="center" valign="top">
		<textarea name="Content" rows="16" cols="60"><%=sContent%>
		</textarea>
		</td>
	</tr>
		<tr>
		<td width="100%" align="left" height="40">
		&nbsp;�ϴ�ͼƬ��<input type="file" name="Pic" size="40"><br>
		&nbsp;<font color="#FF0000">ע�⣺</font>ֻ���ϴ�bmp��gif��jpg��ʽ��ͼƬ����С���ܳ���1.5MB
		</td>
	</tr>
	</table>
	<p>
	<input type="submit" value="����" name="sub">&nbsp;&nbsp;
	<input type="reset" value="���" name="res">
	</p>
	</form>
	</div>
	</body>
</html>
