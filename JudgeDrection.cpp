#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void Judge(string& str, string& a, string& b)
{
	string tmp = a + b;

	if (tmp.size() > str.size())
		cout << "invalid" << endl;
	int index1 = 0;
	for (int i = 0; i < str.size() && index1 < tmp.size(); i++)
	{
		if (str[i] == tmp[index1])
			index1++;
	}

	int index2 = 0;
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.size() && index2 < tmp.size(); i++)
	{
		if (str[i] == tmp[index2])
			index2++;
	}

	if (index1 == tmp.size() && index2 == tmp.size())
		cout << "both" << endl;
	else if (index1 == tmp.size())
		cout << "forward" << endl;
	else if (index2 == tmp.size())
		cout << "backward" << endl;
	else
		cout << "invalid" << endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		string first, second;
		cin >> first;
		cin >> second;
		Judge(str, first, second);
		str = "";
		first = "";
		second = "";
	}

	return 0;
}
