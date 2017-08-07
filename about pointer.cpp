//int(*p)[4]和int*p的区别
#include <iostream>
int main()
{
	int (*arr)[4];
	int * p;
	int ** p2;
	int arr1[4] = { 1, 2, 3, 4 };
	int arr2[2][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
	arr = &arr1;
	//arr = arr2;
	//p2 = arr2;
	p = arr1;
	/*p = arr;*/
}
