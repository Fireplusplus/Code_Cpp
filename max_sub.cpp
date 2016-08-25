/*
 * 有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
 * 给定数组A及它的大小n，请返回最大差值。
 */

class LongestDistance
{
public:
	int getDis(vector<int> A, int n)
	{
		// write code here
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			int m = A[i];
			for (int j = i + 1; j < n; j++)
			{
				if (A[j] > m)
					m = A[j];
			}
			if (m - A[i] > max)
				max = m - A[i];
		}
		return max;
	}
};