
#include <iostream>
#include <cstring>
struct max_Index_len
{
	int maxInex;
	int maxLength;
};
max_Index_len search_longest_len(int * arr, int size, int value);
const int Max = 1024;

int main()
{
	//定义了数组前32个元素的值，后面的值都为0
	int x[Max] = { 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255 };
	max_Index_len max;
	max = search_longest_len(x, sizeof(x), 255);
	std::cout << "The longest length is " << max.maxLength << std::endl;
	std::cout << "The longest Index is " << max.maxInex << std::endl;
	std::cin.get();
}
max_Index_len search_longest_len(int * x, int size, int value)//将数组名、数组所占字节和要找的值传递进函数
{
	int ele_num = size / sizeof(int);
	max_Index_len max1 = { 0, 0 };

	int i = 0;
	while (i < ele_num)
	{
		if (x[i] == value)
		{
			int j = i;
			while (j < ele_num && x[j] == value)
				++j;
			if (max1.maxLength < j - i)
			{	
				max1.maxInex = i;
				max1.maxLength = j - i;
			}
				
			i = j;
		}
		++i;
	}
	return max1;
}