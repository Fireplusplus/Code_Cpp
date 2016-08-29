/*
 * 题目描述
 * 度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，若把网格看成一个坐标轴平行于网格线的坐标系的话，
 * 每个点可以用一对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在正方形的内部或者边界。然后把这个正方形剪下来。问剪掉正方形的最小面积是多少。
 * 输入描述:
 * 第一行一个数n(2≤n≤1000)表示点数，接下来每行一对整数xi,yi(－1e9<=xi,yi<=1e9)表示网格上的点
 * 输出描述:
 * 一行输出最小面积
 */

#include <stdio.h>

int MinArea(int *x, int *y, int n)
{
	if (NULL == x || NULL == y || n < 0)
		return -1;

	int max_x = x[0];
	int min_x = x[0];
	int max_y = y[0];
	int min_y = y[0];
	for (int i = 1; i < n; i++)
	{
		if (x[i] > max_x)
			max_x = x[i];
		if (x[i] < min_x)
			min_x = x[i];
		if (y[i] > max_y)
			max_y = y[i];
		if (y[i] < min_y)
			min_y = y[i];
	}

	int sub_x = max_x - min_x;
	int sub_y = max_y - min_y;
	int area = sub_x > sub_y ? sub_x*sub_x : sub_y*sub_y;
	return area;
}


int main()
{
	int n;
	int *x, *y;

	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		x = new int[n];
		y = new int[n];
		while (i < n)
		{
			scanf("%d%d", x + i, y + i);
			i++;
		}

		int min = MinArea(x, y, n);
		printf("%d\n", min);

		delete[] x;
		delete[] y;
	}

	return 0;
}