<%@ page language="java" import="java.util.*" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html" charset="UTF-8">
<title>登录</title>
		<style>
			body {background-color:#b0c4de;}
		</style>
</head>
	<div align="center">
	<h1>登录页面</h1>
	<div class="loginbody">
	<span class="systemlogo"></span>
	</div>
	<form action="user" method="post">
		<input type="hidden" name="oper" value="login" />
		<ul style="list-style:none">                               
		<li><input name="uname" type="text" placeholder="用户名" class="loginuser"/></li>
		<li><input name="pwd" type="password" placeholder="密码" class="loginpwd" /></li>
		<li><input name="" type="submit" class="loginbtn" value="登录" /></li>
		<a href="http://localhost:8080/HZQ/register.jsp">注册</a>
		</ul>
	</form>
	 </div>
<body>
		
</body>
</html>