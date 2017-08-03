
#include <iostream>
#include <vector>
using std::vector;
vector<int> search_longest_len(vector<int>, int);
vector<int> search_longest_len2(vector<int>, int);

int main()
{
	//定义了数组前32个元素的值，后面的值都为0
	vector<int> x = { 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255 };
	vector<int> len;
	len = search_longest_len2(x, 255);
	std::cout << "The longest length is " << len[1] << std::endl;
	std::cin.get();
}
vector<int> search_longest_len2(vector<int> x,int value)//将数组名和要找的值传递进函数
{
	vector<int> max = {0, 0};//存放最长重复区间的下标位置和长度
	for (int i = 0; i < x.size(); ++i)
	{
		int j;
		for (j = i;j < x.size() && x[i] == value && x[j] == value; ++j);//防止越界

		if (max[1] < (j - i))//判断存储的长度是否小于这次检测的长度
		{
			max[0] = i;
			max[1] = j - i;
		}
		i = j;
	}
	return max;
}

vector<int> search_longest_len(vector<int> x, int value)//将数组名和要找的值传递进函数
{
	int maxIndex, maxLength=0,tempIndex,tempLength=0;
	vector<int> result = { 0, 0 };//存放最长重复区间的下标位置和长度
	for (int i = 0; i < x.size(); ++i)
	{
		if (x[i] == value)
		{
			tempIndex = i;
			tempLength = 0;
			for (int j = i + 1; j < x.size(); ++j)
			{
				if (x[j] == value)
				{
					tempLength++;
				}
				else
				{
					i = j;
					break;
				}
					
			}
		}
		if (tempLength>maxLength)
		{
			maxIndex = tempIndex;
			maxLength = tempLength;
		}
	}
	result[0] = maxIndex;
	result[1] = maxLength;
	return result;
}