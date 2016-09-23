/*
 * 题目描述：
 * 给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
 * 输入
 * 输入为两行内容，第一行是正整数number，注意可能是很大的。第二行是希望去掉的数字数量。
 * 输出
 * 输出保留下来的结果。
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num;
	cin >> num;
	int n;
	cin >> n;

	while (n-- && !num.empty())
	{
		string::iterator pos = num.begin(), min = pos;
		for (++pos; pos != num.end(); ++pos)
		{
			if (*pos < *min)
				min = pos;
		}
		num.erase(min);
	}
	if (num.empty())
		cout << 0 << endl;
	else
		cout << num << endl;

	return 0;
}