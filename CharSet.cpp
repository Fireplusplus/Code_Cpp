/*
 * 题目描述
 * 输入一个字符串，求出该字符串包含的字符集合
 * 输入描述:
 * 每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
 * 输出描述:
 * 每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
 */

#include <stdio.h>
#include <string.h>

void CharSet(char *buf)
{
	int set[52];
	memset(set, 0, 52 * sizeof(set[0]));

	char *str = buf;
	while ('\0' != *str)
	{
		if (*str >= 'a')
			set[*str - 'a' + 26]++;
		else
			set[*str - 'A']++;
		str++;
	}

	for (int i = 0; buf[i] != '\0'; i++)
	{
		int index;
		if (buf[i] >= 'a')
			index = buf[i] - 'a' + 26;
		else
			index = buf[i] - 'A';

		if (set[index] > 0)
		{
			printf("%c", buf[i]);
			set[index] = 0;
		}
	}
	printf("\n");

}

int main()
{
	char buf[101];
	while (scanf("%s", buf) != EOF)
	{
		CharSet(buf);
	}


	return 0;
}