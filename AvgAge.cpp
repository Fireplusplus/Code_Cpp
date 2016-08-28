#define _CRT_SECURE_NO_WARNINGS

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