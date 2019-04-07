package hzq.service.impl;

import hzq.dow.UserDao;
import hzq.dow.impl.UserDaoImpl;
import hzq.pojo.User;
import hzq.service.UserService;

public class UserServiceImpl implements UserService {
	//声明Dao层对象
	UserDao ud = new UserDaoImpl();
	//用户登录
	@Override
	public User checkUserLoginService(String uname, String pwd) {
		User u = ud.checkUserLoginDao(uname, pwd);
		if(u != null) {
			System.out.println("登录成功");
		}else {
			System.out.println("登录失败");
		}
		return u;
	}
	@Override
	public int userChangePwdService(String newPwd, int uid) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	//用户注册
	public int userRegService(User u) {
		return ud.userRegDao(u);
	}

}
