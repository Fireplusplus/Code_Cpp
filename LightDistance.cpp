/*
 * 题目描述
 * 一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai，每盏灯可以覆盖
 * 到的最远距离为d，为了照明需求，所有灯的灯光必须覆盖整条街，但是为了省电，要是这个d最小，请找到这个最小的d。
 * 输入描述:
 * 每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数
 * (均大于等于0小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

float MinDistance(vector<int>& v, int l)
{
	sort(v.begin(), v.end());
	int size = v.size();

	float max = 0;
	for (int i = 1; i < size; i++)
	{
		if (v[i] - v[i - 1] > max)
			max = v[i] - v[i - 1];
	}
	max /= 2;
	if (v[0] > max)
		max = v[0];
	if (l - v[size - 1] > max)
		max = l - v[size - 1];
	return max;
}

int main()
{
	int n, l;
	vector<int> v;
	while (cin >> n >> l)
	{
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		float ret = MinDistance(v, l);
		printf("%.2f\n", ret);
	}

	return 0;
}