#include<iostream>  
#include<cstdio>  
#include<vector>  
#include<string>  
#include<cstring>  
#include<climits>  
#include<queue>  
#include<map>  
#include<algorithm>  
using namespace std;

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		vector<vector<int> > dp(n, vector<int>(k + 1, 0));
		vector<int> prices(n, 0);
		for (int i = 0; i<n; i++)
			scanf("%d", &prices[i]);
		for (int i = 1; i<n; i++)
		{
			for (int t = 1; t <= k; t++)
			{
				int mx = dp[i - 1][t];
				for (int j = i - 1; j >= 0; j--)
					mx = max(mx, dp[j][t - 1] + prices[i] - prices[j]);
				dp[i][t] = mx;
			}
		}
		printf("%d\n", dp[n - 1][k]);
	}
}