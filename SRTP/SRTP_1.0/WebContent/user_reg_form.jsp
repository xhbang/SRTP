<%@ page contentType="text/html; charset=gb2312" language="java"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ϣƽ̨</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
</head>
<body bgcolor="#F5F5F5">
<div align="center">
<h1>������Ϣƽ̨ע��</h1>
<hr width="90%">
<form name="form1" method="post" action="user_reg_save.jsp" target="_self">
<table width=80%>
<tr>
<td align=right width="40%">�������û�����</td>
<td align=left><input name="UserName" size="15" type="text"></td>
</tr>
<tr>
<td align=right>���������룺</td>
<td align=left><input type="password" name="UserPassword" size=31> </td>
</tr>
<tr>
<td align=right>��ȷ�����룺</td>
<td align=left><input type="password" name="CUserPassword" size=31> </td>
</tr>
<tr>
<td align=right>�������ǳƣ�</td>
<td align=left><input name="NickName" size="20"></td>
</tr>
<tr>
<td align=right>��ѡ���Ա�</td>
<td align=left><input type="radio" name="Sex" value="��" checked>��&nbsp;<input type="radio" name="Sex" value="Ů">Ů</td>
</tr>
<tr>
<td align=right>����������Email��</td>
<td align=left><input name="Email" size="20"></td>
</tr>
<tr>
<td align=right>��֤�룺</td>
<td align=left><img src="./image.jsp" name="myImage"></td>
</tr>
<tr>
<td align=right>��������������֣�</td>
<td align=left><input name="Rand" size="4" maxlength="4"></td>
</tr>
</table><br>
<hr width="90%">
<input type="submit" name="sub" value="�ύ">
&nbsp;&nbsp;<input name="res" type="reset" value="����"> 

</form>
</div>
</body>
</html>
