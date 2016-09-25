/*
 * 题目描述：
 * 给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格。
 * 比如：
 * （1） “hello xiao mi”-> “mi xiao hello”
 * 输入
 * 输入数据有多组，每组占一行，包含一个句子(句子长度小于1000个字符)
 * 输出
 * 对于每个测试示例，要求输出句子中单词反转后形成的句子
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string tmp;
	while (cin >> tmp)
	{
		str += tmp;
		str += " ";
	}
	str.erase(str.length()-1, 1);	

	string ret;
	const char* finish = str.c_str();
	char* end = (char*)(finish + str.length() - 1);
	
	while (end >= finish)
	{
		while (end >= finish && *end != ' ')
			end--;
		if (end < finish)
		{
			ret += end + 1;
		}
		else
		{
			*end = '\0';
			ret += end + 1;
			ret += " ";
		}
	}
	cout << ret << endl;

	return 0;
}