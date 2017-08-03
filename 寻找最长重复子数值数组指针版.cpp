
#include <iostream>
#include <cstring>
int search_longest_len(int *, int, int);
const int Max = 1024;

int main()
{
	//定义了数组前32个元素的值，后面的值都为0
int x[Max] = { 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255 };
int len;
len = search_longest_len(x, sizeof(x), 255);
std::cout << "The longest length is "<< len << std::endl;
std::cin.get();
}
int search_longest_len(int * x, int size, int value)//将数组名、数组所占字节和要找的值传递进函数
{
	int *head, *last; 
	int ele_num = size / sizeof(int);
	int *buf = new int[ele_num];
	int maxadress, length;
	int maxlen = 0, i = 1;
	
	memcpy(buf, x, size);
	head = buf;
	while (i < ele_num)
	{
		while (*head != value && i < ele_num)
		{
			++head;
			++i;
		}
				
		if (i < ele_num)//判断是否越界
		{
			for (last = head; *head == *last;)
			{
				last += 1;
				++i;
			}
		}
		else
			continue;
			
			
		length = last - head;
		if (maxlen < length)
		{
			maxlen = length;
			maxadress = i - length;
		}
		head = last;
	}
	std::cout << "The start of longest is " << maxadress << " element\n";
	delete[] buf;
	return maxlen;
	
	
}