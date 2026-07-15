#include <iostream>
using namespace std;

//类模板中成员函数创建时机
//类模板中成员函数在调用时才去创建

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 sohw" << endl;
	};
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 sohw" << endl;
	};
};

template<class T>
class MyClass
{
public:

	T obj;

	//类模板中的成员函数
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	};
};

void test01()
{
	MyClass<Person2>m; //Person1调用和Person2调用都可以创建MyClass类模板对象
	//m.func1();
	m.func2();
}

int main()
{
	test01();

	system("pause");

	return 0;
}