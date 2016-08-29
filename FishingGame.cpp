#define _CRT_SECURE_NO_WARNINGS


/*
 * 题目描述
 * ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子有不同的概率钓上鱼，cc一直在坐标(x,y)的格子钓鱼，
 * 而ss每分钟随机钓一个格子。问t分钟后他们谁至少钓到一条鱼的概率大？为多少？
 * 输入描述:
 * 第一行五个整数n,m,x,y,t(1≤n,m,t≤1000,1≤x≤n,1≤y≤m);
 * 接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i,j)的格子钓到鱼的概率为p(0≤p≤1)
 * 输出描述:
 * 输出两行。第一行为概率大的人的名字(cc/ss/equal),第二行为这个概率(保留2位小数)
 */

#include <stdio.h>

void MaxP(float *p, int n, int m, int x, int y, int t)
{
	x--;
	y--;
	int size = n * m;
	float ssP = 0.0f;
	for (int i = 0; i < size; i++)
		ssP += p[i];
	ssP = ssP / size * t;

	float ccP = p[x*n + y] * t;

	if (ssP > ccP)
		printf("ss\n%.2f\n", ssP);
	else if (ssP < ccP)
		printf("cc\n%.2f\n", ccP);
	else
		printf("equal\n%.2f\n", ssP);
}

int main()
{
	int n, m, x, y, t;
	float *p;
	while (scanf("%d%d%d%d%d", &n, &m, &x, &y, &t) != EOF)
	{
		p = new float[n * m];
		int i = 0;
		int size = n * m;
		while (i < size)
		{
			scanf("%f", p + i);
			i++;
		}

		MaxP(p, n, m, x, y, t);

		delete[] p;
	}

	return 0;
}