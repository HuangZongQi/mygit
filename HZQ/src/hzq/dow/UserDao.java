package hzq.dow;

import hzq.pojo.User;

public interface UserDao {
	/***
	 *  根据用户名和密码查询拥护信息
	 * @param name	用户名
	 * @param pwd	密码
	 * @return	返回查询到的用户信息
	 */
		User checkUserLoginDao(String uname,String pwd);
		
		/**
		 * 用户注册
		 * u
		 */
		int userRegDao(User u);
}
