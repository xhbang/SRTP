<%@ page contentType="text/html; charset=gb2312" language="java"  %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ϣƽ̨</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
<jsp:useBean scope="page" id="User" class="com.User" />

<%
	//��ȡsession�б����UserName����ֵ
	String sUserName = (String) session.getAttribute("UserName");
	//��ȡsession�б����UserID
	long lUserID = (Long) session.getAttribute("UserID");	
	User.setUserID(lUserID);	
	//��ʼ���û���Ϣ
	User.init();
%>
</head>
<body>
<div align="center"><br>
<h3>�޸�����</h3>
<form name="form1" method="post" action="modify_password_save.jsp" target="_self">
<table width="80%" border="0">
<tr>
<td width="50%" align="right" height="25">����������룺</td>
<td width="50%" align="left" height="25"><input name="OldUserPassword" type="password" size="20"></td>
</tr>
<tr>
<td width="50%" align="right" height="25">�����������룺</td>
<td width="50%" align="left" height="25"><input name="UserPassword" type="password" size="20" ></td>
</tr>
<tr>
<td width="50%" align="right" height="25">��ȷ�������룺</td>
<td width="50%" align="left" height="25"><input name="CUserPassword" type="password" size="20" ></td>
</tr>
<tr>
<td width="100%" align="center" height="30" colspan="2">
<input type="submit" name="sub" value="�޸�">
&nbsp;&nbsp;
<input type="reset" name="res" value="����">
</td>
</tr>
</table>
</form>
<h3>�޸�������Ϣ</h3>
<form name="form2" method="post" action="modify_info_save.jsp" target="_self">
<table width="80%" border="0">
<tr>
<td width="50%" align="right" height="25">�û�����</td>
<td width="50%" align="left" height="25">&nbsp;<font color="#0000FF"><%=sUserName%></font></td>
</tr>
<tr>
<td width="50%" align="right" height="25">�ǳƣ�</td>
<td width="50%" align="left" height="25"><input name="NickName" type="text" size="20" value="<%=User.getNickName()%>"></td>
</tr>
<tr>
<td width="50%" align="right" height="25">�Ա�</td>
<td width="50%" align="left" height="25">
<input type="radio" name="Sex" value="��" <%if(User.getSex().compareTo("��") == 0)  out.println("checked");%>>��&nbsp;
<input type="radio" name="Sex" value="Ů" <%if(User.getSex().compareTo("Ů") == 0) out.println("checked");%>>Ů
</tr>
<tr>
<td width="50%" align="right" height="25">Email��</td>
<td width="50%" align="left" height="25"><input name="Email" type="text" size="20" value="<%=User.getEmail()%>"></td>
</tr>
<tr>
<td width="100%" align="center" height="30" colspan="2">
<input type="submit" name="sub" value="�޸�">
&nbsp;&nbsp;
<input type="reset" name="res" value="����">
</td>
</tr>
</table>
</form>
</div>
</body>
</html>
