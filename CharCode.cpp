#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

struct Greater
{
	bool operator()(char left, char right)
	{
		return left > right;
	}
};

int min_len(const string& str)
{
	const char* s = str.c_str();
	int hash[256];
	memset(hash, 0, sizeof(hash));
	int i = 0;
	for (; i < str.size(); i++)
	{
		hash[*(s + i)]++;
	}
	sort(hash, hash + 256, Greater());

	int len = 0;
	int cnt = 1;
	for (i = 0; i < 256 && hash[i] != 0; i++)
	{
		if (i == 255 || hash[i + 1] == 0)
			break;
		len += cnt * hash[i];
		cnt++;
	}
	len += cnt * hash[i];

	return len;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int ret = min_len(str);
		cout << ret << endl;
		str = "";
	}

	return 0;
}