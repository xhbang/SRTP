<%@ page contentType="text/html; charset=gb2312" language="java" %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ϣƽ̨</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
<jsp:useBean scope="page" id="Email" class="com.Email" />
<jsp:useBean scope="page" id="Article" class="com.Article" />
<jsp:useBean scope="page" id="User" class="com.User" />
</head>
<%
	//��ȡ��ǰ�û����û���
	String sUserName = (String) session.getAttribute("UserName");
	String sSubject = "";
	String sContent = "";
	String sReceiver = "";
	//�����Ҫ�ظ����ʼ��������ţ�������ת��Ϊ������	
	String sEmailID = request.getParameter("EmailID");
	long lEmailID = Long.parseLong(sEmailID);

	//�ж��Ƿ��ǻظ��ʼ�������ǵĻ����ȡ�ʼ���Ϣ
	if(lEmailID != 0)
	{
		Email.setEmailID(lEmailID);
		Email.init();
		sSubject = "�ظ���"+Email.getSubject();		
		sReceiver = Email.getSender();
		sContent = Email.getContent();
		if(sContent.length()>100)
		{
			sContent = sContent.substring(1,100);
			sContent = sContent + "������������";
		}
		sContent = "�� �� "+sReceiver+" ���������ᵽ: ��\r\n" + sContent;
		sContent = "\r\n\r\n\r\n\r\n----------------------------------------------------------\r\n" + sContent;
	}
	//��ȡ��Ҫ���ŵ����µ������ţ�������ת��Ϊ������
	String sArticleID = request.getParameter("ArticleID");
	long lArticleID = Long.parseLong(sArticleID);

	//�ж��Ƿ��ǻ������£�����ǵĻ����ȡ������Ϣ
	if(lArticleID != 0)
	{
		Article.setArticleID(lArticleID);
		Article.init();		
		sSubject = "�ظ���"+Article.getTitle();		
		User.setUserID(Article.getUserID());
		User.init();
		sReceiver = User.getUserName();
		sContent = Article.getContent();				
		if(sContent.length()>100)
		{
			sContent = sContent.substring(1,100);
			sContent = sContent + "������������";
		}
		sContent = "�� �� "+sReceiver+" ���������ᵽ: ��\r\n" + sContent;
		sContent = "\r\n\r\n\r\n\r\n----------------------------------------------------------\r\n" + sContent;
	}
%>
<body>
<div align="center">
<br>
<form name="form1" method="post" action="send_email_save.jsp" target="_self">
<table width="400" border="0" cellpadding="0" cellspacing="1">
<tr>
<td align="left">
�����ˣ�<font color="#0000FF"><%=sUserName%></font><br>
��&nbsp;&nbsp;��: <input type="text" name="Subject" size="50" value="<%=sSubject%>"> <br>
�����ˣ�<input type="text" name="Receiver" value="<%=sReceiver%>">&nbsp;&nbsp; <br>
<textarea name="Content" rows="16" cols="60"><%=sContent%>
</textarea>
<p align="center">
<input type="submit" value="����" name="sub">
&nbsp;&nbsp;
<input type="reset" value="��д" name="res">
</p>
</table>
</form>
</div>
</body>
</html>
