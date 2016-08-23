class BinarySearch 
{
public:
    int getPos(vector<int> A, int n, int val) 
    {
        // write code here
        int left = 0;
        int right = n - 1;
        int mid;
        while (left <= right)
        {
            mid = ((right - left) >> 1) + left;
            if (A[mid] < val)
            	left = mid + 1;
            else if (A[mid] > val)
                right = mid - 1;
            else
                break;
        }
        if (left > right)
            return -1;
        while (mid > 0)
       	{
            if (A[mid] == A[mid - 1])
            	mid--;
            else
                break;
        }
        return mid;
    }
};
