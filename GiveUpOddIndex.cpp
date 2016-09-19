/*
 * 题目描述
 * 对于一个由0..n的所有数按升序组成的序列，我们要进行一些筛选，每次我们取当前所有数字中从小到大的第奇数位个的数，
 * 并将其丢弃。重复这一过程直到最后剩下一个数。请求出最后剩下的数字。
 * 输入描述:
 * 每组数据一行一个数字，为题目中的n(n小于等于1000)。
 * 输出描述:
 * 一行输出最后剩下的数字。
 */

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		list<int> l;
		for (int i = 0; i <= n; i++)
			l.push_back(i);
		list<int>::iterator pos = l.begin(), next;

		while (l.size() != 1)
		{
			next = pos;
			++next;
			l.erase(pos);
			pos = next;
			++pos;
			if (pos == l.end())
				++pos;
		}
		cout << *pos << endl;
	}


	return 0;
}