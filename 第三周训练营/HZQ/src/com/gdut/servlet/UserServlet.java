package com.gdut.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import hzq.pojo.User;
import hzq.service.UserService;
import hzq.service.impl.UserServiceImpl;

/**
 * Servlet implementation class UserServlet
 */
public class UserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
  
	@Override
		protected void service(HttpServletRequest req, HttpServletResponse resp) 
				throws ServletException, IOException {
			//设置请求编码格式
			req.setCharacterEncoding("utf-8");
			//设置响应编码格式
			resp.setContentType("text/html;charset=utf-8");
			//获取操作符
			String oper = req.getParameter("oper");			
				if("login".equals(oper)) {
				//调用登录方法
				checkUserLogin(req,resp);
			}else if("reg".equals(oper)){
				//调用注册功能
				UserReg(req,resp);
			}else {
				System.out.println("没有找到对应操作符："+oper);
			}
			
	}
	//注册用户
	private void UserReg(HttpServletRequest req, HttpServletResponse resp) {
		//获取请求信息
			String uname = req.getParameter("uname");
			String pwd = req.getParameter("pwd");
			String sex = req.getParameter("sex");
			System.out.println("uname:"+uname +" pwd:"+ pwd +" sex:"+ sex);
			User u =  new User(2,uname,pwd,sex);
		//处理处理信息
			//调用业务层处理
			UserService us = new UserServiceImpl();
			int index = us.userRegService(u);
			System.out.println(index);
		//响应请求结果
			try {
			if(index > 0) {
				//重定向
				resp.sendRedirect("http://localhost:8080/HZQ/RegisterSuccess.jsp");
		}else {
			resp.sendRedirect("http://localhost:8080/HZQ/RegisterFailuer.jsp");
		}
			}	catch (IOException e) {
				e.printStackTrace();
			}
	}
	//
	//处理登录
	private void checkUserLogin(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException{
		//获取请求信息
		String uname = req.getParameter("uname");
		String pwd = req.getParameter("pwd");
		System.out.println("用户名："+uname+" "+" "+"密码："+pwd);
		//处理请求信息
			//获取service层对象
			UserService us = new UserServiceImpl();
			//校验
			User u = us.checkUserLoginService(uname,pwd);
			System.out.println(u);
			if(u != null) {
				//获取session对象
				HttpSession hs = req.getSession();
				//将用户数据存储到session中
				hs.setAttribute("user", u);
				//重定向
					resp.sendRedirect("http://localhost:8080/HZQ/LoginSuccess.jsp");
					return ;
				}else {
				//请求转发
				req.getRequestDispatcher("/LoginFailuer.jsp").forward(req, resp);
				return ;
			}
		//响应请求信息
				//直接响应
				//请求转发
				
				
		}
}
