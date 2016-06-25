/* 
 * Given two sorted integer arrays A and B, merge B to A as one 
 * sorted
 */

class Solution
{
public:
	void merge(int A[], int m, int B[], int n)
	{
		int ia = m - 1;
		int ib = n - 1;
		int icur = m + n - 1;
		
		if (NULL == A || NULL == B)
			return;
		if (n <= 0 || m < 0)
			return;

		//依次归并A和B中的元素至A中
		while (ia >= 0 && ib >= 0)
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
		//若B有剩余，则并入；若A有剩余，则不用处理
		while (ib >= 0)
			A[icur--] = B[ib--];
	}

};
