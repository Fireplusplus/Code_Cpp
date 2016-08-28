/*
 * C市现在要转移一批罪犯到D市，C市有n名罪犯，按照入狱时间有顺序，另外每个罪犯有一个罪行值，值越大罪越重。
 * 现在为了方便管理，市长决定转移入狱时间连续的c名犯人，同时要求转移犯人的罪行值之和不超过t，问有多少种选择的方式？
 * 输入描述:
 * 第一行数据三个整数:n，t，c(1≤n≤2e5,0≤t≤1e9,1≤c≤n)，第二行按入狱时间给出每个犯人的罪行值ai(0≤ai≤1e9)
 * 输出描述:
 * 一行输出答案。
 */

#include <stdio.h>

int MethodsNum(int crime[], int n, int t, int c)
{
	if (NULL == crime || n <= 0 || c > n)
		return 0;
	int first = 0, second = 0;
	int cnt = 0;
	int sum = 0;
	for (; second < c; second++)
	{
		sum += crime[second];
	}
	second--;

	while (second < n)
	{
		if (t >= sum)
		{
			cnt++;
		}

		sum -= crime[first++];
		if (++second > n)
			break;
		sum += crime[second];
	}

	return cnt;
}

int main()
{
	int n, t, c;
	int *crime;
	while (scanf("%d%d%d", &n, &t, &c) != EOF)
	{
		crime = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", crime + i);
		}
		int ret = MethodsNum(crime, n, t, c);
		printf("%d\n", ret);

		delete[] crime;
	}

	return 0;
}