#define _CRT_SECURE_NO_WARNINGS

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