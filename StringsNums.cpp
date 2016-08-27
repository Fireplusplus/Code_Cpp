/*
 * 求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。
 * 输入描述:
 * 每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
 */

#include <stdio.h>
#include <string.h>

int StrToInt(const char *str)
{
	int ret = 0;
	const char *tmp = str;
	while (*tmp != '\0')
	{
		ret = ret * 26 + (*tmp) - 'a';
		tmp++;
	}

	return ret;
}

int StringNums(char *str1, char *str2, int len1, int len2)
{
	if (len1 > len2 || str1 == NULL || str2 == NULL)
		return 0;
	int l1 = strlen(str1);
	int l2 = strlen(str2);

	if (len1 > l1)
	{
		int i = l1;
		while (i < len1)
		{
			str1[i++] = 'a';
		}
		str1[i] = '\0';
	}
	if (len2 > l2)
	{
		int i = l2;
		while (i < len2)
		{
			str2[i++] = 'a';
		}
		str2[i] = '\0';
	}

	int IntStr1 = StrToInt(str1);
	int IntStr2 = StrToInt(str2);

	return (IntStr2 - IntStr1 - 1) % 1000007;
}

int main()
{
	char str1[100];
	char str2[100];
	int len1, len2;

	while (scanf("%s%s%d%d", str1, str2, &len1, &len2) != EOF)
	{
		int ret = StringNums(str1, str2, len1, len2);
		printf("%d\n", ret);
	}

	return 0;
}