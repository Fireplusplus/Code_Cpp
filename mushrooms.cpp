/*
 * 现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。现在A想要拜访B，
 * 由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),
 * 问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
 * 输入描述:
 * 第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。
 * 输出描述:
 * 输出一行，代表所求概率(保留到2位小数)
 */

#include <stdio.h>

#define INDEX(x,y) (((x)*n)+(y))

float visit(int *map, int n, int m)
{
	int i;
	// 对（0，0）行列初始化，遇到蘑菇（-1）前全置1，遇到后全清0
	for (i = 1; i < m; i++)
		map[INDEX(0, i)] = map[INDEX(0, i)] == -1 ? 0 : map[INDEX(0, i - 1)];
	for (i = 1; i < n; i++)
		map[INDEX(i, 0)] = map[INDEX(i, 0)] == -1 ? 0 : map[INDEX(i - 1, 0)];

	for (i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			map[INDEX(i, j)] = map[INDEX(i, j)] == -1 ? 0 : map[INDEX(i, j - 1)] + map[INDEX(i - 1, j)];
		}
	}
	float methods = map[INDEX(n - 1, m - 1)];

	// 总方法数
	for (i = 1; i < m; i++)
		map[INDEX(0, i)] = 1;
	for (i = 1; i < n; i++)
		map[INDEX(i, 0)] = 1;

	for (i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			map[INDEX(i, j)] = map[INDEX(i, j - 1)] + map[INDEX(i - 1, j)];
		}
	}
	float sum = map[INDEX(n - 1, m - 1)];

	return methods / sum;
}

int main()
{
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		int *map = new int[n * m];
		map[INDEX(0, 0)] = 1;

		int i = 0;
		int x, y;
		while (i < k)
		{
			scanf("%d%d", &x, &y);
			x--;
			y--;
			map[INDEX(x, y)] = -1;
			i++;
		}

		float ret = visit(map, n, m);
		printf("%.2f\n", ret);

		delete[] map;
	}

	return 0;
}
