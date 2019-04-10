<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<style>
			body {background-color:#b0c4de;}
		</style>
<title>Insert title here</title>
</head>
<body>
	<center>登录失败,稍后跳转登录页面......</center>
	<br />
	<div style="text-align: center;">
	<span  style="font-size: 20px;">用户名或密码错误</span>
	</div>
	<%
		response.setHeader("refresh","3;http://localhost:8080/HZQ/login.jsp");
	%>

</body>
</html>