/* 
 * 有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。
 * 有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到最多的宝石。
 * 输入
 * 我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
 * 输出
 * 输出学者能够拿到的最多的宝石数量。每行一个
 */

#include <iostream>
#include <string>

using namespace std;

int Cnt(string &list, int cur, string tar)
{
	int cnt = 0;	// 需要切割的数量
	int pos = cur;
	const char* str = list.c_str();
	for (; pos < list.length(); ++pos)
	{
		cnt++;
		if (*(str + pos) >= 'A' && *(str + pos) <= 'E')
		{
			for (size_t i = 0; i < tar.size(); i++)
			{
				if (*(str + pos) == tar[i])
				{
					tar.erase(i, 1);
					break;
				}
			}
			if (tar.empty())
				return cnt;
		}
	}

	for (pos = 0; pos != cur; ++pos)
	{
		cnt++;
		if (*(str + pos) >= 'A' && *(str + pos) <= 'E')
		{
			for (size_t i = 0; i < tar.size(); i++)
			{
				if (*(str + pos) == tar[i])
				{
					tar.erase(i, 1);
					break;
				}
			}
			if (tar.empty())
				return cnt;
		}
	}
	return -1;
}

int main()
{
	string tar("ABCDE");
	string list;
	cin >> list;

		int min = -1;
		int p = 0;
		const char* str = list.c_str();

		for (; p < list.length(); ++p)
		{
			if (*(str + p) >= 'A' && *(str + p) <= 'E')
			{
				int ret = Cnt(list, p, tar);
				if (ret == -1)
					continue;
				if (ret < min || min == -1)
					min = ret;
			}
		}
		cout << list.length() - min << endl;


	return 0;
}