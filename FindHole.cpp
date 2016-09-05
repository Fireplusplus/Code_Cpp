/*
 * 题目描述
 * 一只兔子藏身于20个圆形排列的洞中（洞从1开始编号），一只狼从x号洞开始找,下次隔一个洞找(及在x＋2号洞找)，
 * 在下次个两个洞找(及在x＋5号洞找)，它找了n次仍然没有找到。问兔子可能在那些洞中。
 * 输入描述:
 * 输入有多组数据，每组数据一行两个整数分别为x和n(x <= 20,n <= 100000)
 * 输出描述:
 * 每组数据一行按从小到大的顺序输出兔子可能在的洞，数字之间用空格隔开。若每个洞都不肯能藏着兔子，输出-1。
 */

#include <stdio.h>
#include <string.h>

void FindHole(int x, int n)
{
	char arr[20];
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++)
	{
		x %= 20;
		arr[x]++;
		x += i + 2;
	}

	int cnt = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i] == 0)
		{
			printf("%d ", i + 1);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("-1\n");
	else
		printf("\n");
}

int main()
{
	int x, n;
	while (scanf("%d%d", &x, &n) != EOF)
	{
		x--;
		FindHole(x, n);
	}

	return 0;
}