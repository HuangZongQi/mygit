package hzq.service;

import hzq.pojo.User;

public interface UserService {
	/**
	 * 校验用户登录
	 * @param uname 用户名
 	 * @param pwd 	用户密码
	 * @return	返回查询到的用户信息
	 */
		User checkUserLoginService(String uname,String pwd);
		/**
		 * 修改用户密码
		 * newpwd
		 * uid
		 */
		int userChangePwdService(String newPwd, int uid);
		/**
		 * 用户注册
		 * u
		 * return
		 */
		int userRegService(User u);
}
