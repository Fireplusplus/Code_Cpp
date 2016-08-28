#define _CRT_SECURE_NO_WARNINGS

/* 
 * 已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，假设每年离职率为x，x>0&&x<1,
 * 每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。
 * 从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(结果向上取整)。
 * 输入描述:
 * 输入W Y x N
 * 输出描述:
 * 输出第N年后的平均年龄 
 */

#include <stdio.h>

int AvgNextYear(int W, int Y, float x)
{
	double rs = ((1 - x)*W*Y + W*x * 21) / W;
	int avg = (int)rs;
	if (rs > avg)
		avg++;
	return avg;
}

int NYearAvg(int W, int Y, float x, int N)
{
	int avg = Y;
	while (N--)
	{
		avg = AvgNextYear(W, avg, x);
	}
	return avg;
}

int main()
{
	int W, Y, N;
	float x;
	while (scanf("%d%d%f%d", &W, &Y, &x, &N) != EOF)
	{
		int avg = NYearAvg(W, Y, x, N);
		printf("%d", avg);
	}

	return 0;
}
