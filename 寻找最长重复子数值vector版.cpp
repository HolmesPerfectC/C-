
#include <iostream>
#include <vector>
using std::vector;
vector<int> search_longest_len(vector<int>, int);

int main()
{
	//����������ǰ32��Ԫ�ص�ֵ�������ֵ��Ϊ0
	vector<int> x = { 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255 };
	vector<int> len;
	len = search_longest_len(x, 255);
	std::cout << "The longest length is " << len[1] << std::endl;
	std::cin.get();
}
vector<int> search_longest_len(vector<int> x,int value)//����������Ҫ�ҵ�ֵ���ݽ�����
{
	vector<int> max = {0, 0};//�����ظ�������±�λ�úͳ���
	for (int i = 0; i < x.size(); ++i)
	{
		int j;
		for (j = i; j < x.size() && x[i] == value && x[j] == value; ++j);//��ֹԽ��
		if (max[1] < (j - i))//�жϴ洢�ĳ����Ƿ�С����μ��ĳ���
		{
			max[0] = i;
			max[1] = j - i;
		}
		i = j;
	}
	return max;
}