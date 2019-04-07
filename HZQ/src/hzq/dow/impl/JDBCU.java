package hzq.dow.impl;

import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import com.mysql.jdbc.Statement;
import java.sql.Connection;

public class JDBCU {
	
		private static final String URL = "jdbc:mysql://localhost:3306/testjdbc";
		private static final String USERNAME =	"root"	;
		private static final String PWD =	"123456" ;
		
		public static Connection getMysqlConn() {
			try {
				Class.forName("com.mysql.jdbc.Driver");
				return DriverManager.getConnection(URL,USERNAME,PWD);
			} catch (SQLException e) {
				e.printStackTrace();
				return null;
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
				return null;
			} 
		}
		public static void close(ResultSet rs,PreparedStatement ps,Connection conn){
				try {
					if(ps != null) {
						ps.close();
					}
				} catch (SQLException e) {
					e.printStackTrace();
				}
				try {
					if(conn != null) {
						conn.close();
					} 
				}catch (SQLException e) {
					e.printStackTrace();
				}
				try {
					if(conn != null) {
						conn.close();
					}
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		public static void close(Statement ps,Connection conn) {
					try {
						if(ps != null) {
							ps.close();
						}
					}catch (SQLException e) {
						e.printStackTrace();
					}		
					try {
						if(conn != null) {
							conn.close();
						} 
					}catch (SQLException e) {
						e.printStackTrace();
					}
		}
		public static void close(Connection conn) {
			try {
				if(conn != null) {
					conn.close();
				}
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
