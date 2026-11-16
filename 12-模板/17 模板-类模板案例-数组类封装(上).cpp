#include <iostream>
using namespace std;
#include "MyArray.hpp"

void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);   // 拷贝构造
	MyArray<int> arr3(10);
	arr3 = arr1;
}

int main()
{
	test01();

	system("pause");

	return 0;
}