/*
 * 题目描述
 * 小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。
 * 每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,若想让这门课的考试成绩多拿一分的话，
 * 小v要花bi 的时间复习，不复习的话当然就是0分。同时我们显然可以发现复习得再多也不会拿到超过满分的分数。
 * 为了拿到奖学金，小v至少要花多少时间复习。
 * 输入描述:
 * 第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，接下来n行，
 * 每行两个整数ai和bi，均小于等于1e6大于等于1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int a;
	int b;

	friend bool operator<(const info& left, const info& right)
	{
		return left.b < right.b;
	}
};

int Time(info* p, int n, int r, int avg)
{
	vector<info> v(p, p + n);
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i].a;
	}
	sum = n*avg - sum;
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum - (r - v[i].a) <= 0)
		{
			time += sum*v[i].b;
			return time;
		}
		int grade = r - v[i].a;
		sum -= grade;
		time += grade * v[i].b;
	}

	return time;
}

int main()
{
	int n, r, avg;
	while (cin >> n >> r >> avg)
	{
		info *p = new info[n];

		for (int i = 0; i < n; i++)
		{
			cin >> p[i].a >> p[i].b;
		}

		int ret = Time(p, n, r, avg);
		cout << ret << endl;

		delete[] p;
	}


	return 0;
}