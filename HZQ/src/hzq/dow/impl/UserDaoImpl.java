package hzq.dow.impl;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import hzq.dow.UserDao;
import hzq.pojo.User;

public class UserDaoImpl implements UserDao{
	//根据用户名和密码查询拥护信息
	@Override
	public User checkUserLoginDao(String uname, String pwd) {
		//声明jdbc对象
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		//声明变量
		User u = null;
		try {
		//获取连接
		conn =  JDBCU.getMysqlConn();
		//创建sql命令
		String sql = "select * from t_user where uname=? and pwd=?";
		//创建sql命令对象
		ps = conn.prepareStatement(sql);
		//给占位符赋值
		ps.setString(1, uname);
		ps.setString(2, pwd);
		//执行sql
		rs = ps.executeQuery();
		//遍历结果
		while(rs.next()) {
			//给变量赋值
			u = new User();
			u.setUid(rs.getInt("uid"));
			u.setUname(rs.getString("uname"));
			u.setSex(rs.getString("sex"));
			u.setPwd(rs.getString("pwd"));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
		//关闭资源
			JDBCU.close(rs, ps, conn);
		}	
		//返回结果
		
		return u;
	}
	//用户注册
	@Override
	public int userRegDao(User u) {
		//声明JDBC对象
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		//声明变量
		int index = -1;
		//获取连接
		conn = JDBCU.getMysqlConn();
		//创建SQL命令
		String sql = "insert into t_user values(default,?,?,?)";
		//创建SQL命令对象
		try {
			ps = conn.prepareStatement(sql);
			//执行占位符
			ps.setString(1, u.getUname());
			ps.setString(2, u.getPwd());
			ps.setString(3,u.getSex());
			//执行
			index = ps.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		}finally {
			//关闭资源
			JDBCU.close(rs, ps, conn);
		}
		//返回结果
		return index;
	}
	
}
