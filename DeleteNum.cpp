/* 
 * 题目描述
 * 有一个数组a[N]顺序存放0~N - 1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以8个数(N = 7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除), 如此循环直到最后一个数被删除。
 * 输入描述 :
 * 每组数据为一行一个整数n(小于等于1000)，为数组成员数, 如果大于1000，则对a[999]进行计算。
 * 输出描述 :
 * 一行输出最后一个被删掉的数的原始下标位置。
 */

#include <iostream>
#include <list>

using namespace std;

int LastIndex(int n)
{
	list<int> l;
	int i = 0;
	while (i < n)
	{
		l.push_back(i);
		i++;
	}

	list<int>::iterator pos = l.begin();
	list<int>::iterator del;
	while (l.size() > 1)
	{
		++pos;
		if (pos == l.end())
			pos = l.begin();
		++pos;
		if (pos == l.end())
			pos = l.begin();
		del = pos;
		++pos;
		if (pos == l.end())
			pos = l.begin();
		l.erase(del);
	}
	return *pos;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n > 1000)
			n = 1000;
		int ret = LastIndex(n);
		printf("%d\n", ret);
	}

	return 0;
}