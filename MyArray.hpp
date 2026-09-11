#include <iostream>
using namespace std;

template<class T>
class MyArray {
	

public:

	//有参构造 参数 容量
	MyArray(int capacity) {
		cout << "MyArray 有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "Myarray拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];

		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator = 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		cout << "Myarray 的 operator=调用" << endl;
		//先判断原来堆区是否有数据,如果有先释放
		if (this -> pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "Myarray析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:

	T * pAddress; // 指针指向堆区开辟的真实数值

	int m_Capacity; // 数组容量

	int m_Size; //数值大小

};