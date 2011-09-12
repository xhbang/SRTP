<%@ page contentType="text/html; charset=gb2312" language="java"  %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>电子信息平台</title>
<link rel=stylesheet type=text/css href="./lib/bbs.css">
<jsp:useBean scope="page" id="User" class="com.User" />

<%
	//获取session中保存的UserName属性值
	String sUserName = (String) session.getAttribute("UserName");
	//获取session中保存的UserID
	long lUserID = (Long) session.getAttribute("UserID");	
	User.setUserID(lUserID);	
	//初始化用户信息
	User.init();
%>
</head>
<body>
<div align="center"><br>
<h3>修改密码</h3>
<form name="form1" method="post" action="modify_password_save.jsp" target="_self">
<table width="80%" border="0">
<tr>
<td width="50%" align="right" height="25">请输入旧密码：</td>
<td width="50%" align="left" height="25"><input name="OldUserPassword" type="password" size="20"></td>
</tr>
<tr>
<td width="50%" align="right" height="25">请输入新密码：</td>
<td width="50%" align="left" height="25"><input name="UserPassword" type="password" size="20" ></td>
</tr>
<tr>
<td width="50%" align="right" height="25">请确认新密码：</td>
<td width="50%" align="left" height="25"><input name="CUserPassword" type="password" size="20" ></td>
</tr>
<tr>
<td width="100%" align="center" height="30" colspan="2">
<input type="submit" name="sub" value="修改">
&nbsp;&nbsp;
<input type="reset" name="res" value="重填">
</td>
</tr>
</table>
</form>
<h3>修改其他信息</h3>
<form name="form2" method="post" action="modify_info_save.jsp" target="_self">
<table width="80%" border="0">
<tr>
<td width="50%" align="right" height="25">用户名：</td>
<td width="50%" align="left" height="25">&nbsp;<font color="#0000FF"><%=sUserName%></font></td>
</tr>
<tr>
<td width="50%" align="right" height="25">昵称：</td>
<td width="50%" align="left" height="25"><input name="NickName" type="text" size="20" value="<%=User.getNickName()%>"></td>
</tr>
<tr>
<td width="50%" align="right" height="25">性别：</td>
<td width="50%" align="left" height="25">
<input type="radio" name="Sex" value="男" <%if(User.getSex().compareTo("男") == 0)  out.println("checked");%>>男&nbsp;
<input type="radio" name="Sex" value="女" <%if(User.getSex().compareTo("女") == 0) out.println("checked");%>>女
</tr>
<tr>
<td width="50%" align="right" height="25">Email：</td>
<td width="50%" align="left" height="25"><input name="Email" type="text" size="20" value="<%=User.getEmail()%>"></td>
</tr>
<tr>
<td width="100%" align="center" height="30" colspan="2">
<input type="submit" name="sub" value="修改">
&nbsp;&nbsp;
<input type="reset" name="res" value="重填">
</td>
</tr>
</table>
</form>
</div>
</body>
</html>
