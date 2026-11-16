#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//成员属性设置私有
//1、可以自己控制读写权限
//2、对于写可以检测数据有效性

//人类
class person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}
	//设置年龄 (0~150)
	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			cout << "年龄" << age << "输入有误，赋值失败" << endl;
			return;
		}
		m_Age = age;
	}

	//设置偶像
	void setIdol(string idol)
	{
		m_Idol = idol;
	}

private:
	string m_Name; //姓名 可读可写

	int m_Age = 18; //年龄 只读 也可以写 (年龄必须在 0 到 150之间)

	string m_Idol; //偶像 只写
};

int main()
{
	person p;
	//姓名设置
	p.setName("张三");
	cout << "姓名：" << p.getName() << endl;

	//年龄设置
	p.setAge(160);
	//p.m_Age = 20;
	//获取年龄
	cout << "年龄：" << p.getAge() << endl;

	//偶像设置
	p.setIdol("小明");//只写
	//cout << "偶像： " << p.getIdol() << endl; //只写状态 外界访问不到

	system("pause");
	return 0;
}