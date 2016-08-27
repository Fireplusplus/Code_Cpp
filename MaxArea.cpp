/*
 * 有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。
 * 比如，对于直方图[2,7,9,4],它所包含的最大矩形的面积为14(即[7,9]包涵的7x2的矩形)。
 * 给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内。
 */

class MaxInnerRec
{
public:
	int countArea(vector<int> A, int n)
	{
		// write code here
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				int height = MinHeight(A, i, j);
				int area = height * (j - i + 1);
				if (area > max)
					max = area;
			}
		}
		return max;
	}

	int MinHeight(vector<int> &A, int i, int j)
	{
		int min = A[i];
		for (int k = i + 1; k <= j; k++)
		{
			if (A[k] < min)
				min = A[k];
		}
		return min;
	}
};