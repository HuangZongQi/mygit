<%@ page language="java" import="java.util.*,com.gdut.servlet.*,hzq.pojo.*" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<style>
			body {background-color:#b0c4de;}
		</style>
<title>注册</title>
</head>
<body>
	<div align="center">
	<table border="0">
	</div>
		<div class="loginbody">
		<span class="systemlogo"></span>
		<style>
			body {background-color:#b0c4de;}
		</style>
	</div>
	<form action="user" method="post">
		<input type="hidden" name="oper" value="reg"  />
		<h1>注册页面</h1>
		<ul style="list-style:none">                               
			<li><input name="uname" type="text" placeholder="用户名" class="loginuser" /></li>
			<li><input name="pwd" type="password" placeholder="密码" class="loginpwd"/></li>
			<li><input name="pwd" type="password" placeholder="再次输入密码" class="loginpwd" /></li>
			<li>男<input type="radio" name="sex" value="男" checked="checeked"/>
			          女<input type="radio" name="sex" value="女" /><li>
				<li><input name="" type="submit" class="loginbtn" value="注册" /></li>
		</ul>
	</table>
	</form>
	</div>
</body>
</html>