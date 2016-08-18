/* 
 * 风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 
 * 给你一个回顾历史的机会，已知一支股票连续n天的价格走势，以长度为n
 * 的整数数组表示，数组中第i个元素（prices[i]）代表该股票第i天的股价。 
 * 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，
 * 并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。
 * 设计算法，计算你能获得的最大收益。 
 * 输入数值范围：2<=n<=100,0<=prices[i]<=100 
 */

class Solution 
{
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) 
    {
        int sum = 0;
		for (int i = 0; i < prices.size(); i++)
        {
            int tmp = getmax(prices, 0, i - 1) + getmax(prices, i, prices.size() - 1);
            if (tmp > sum)
               sum = tmp;
        }
        return sum;
    }
    
    int getmax(vector<int> &vec, int left, int right)
    {
        if (left == right)
            return 0;
        int min = vec[left];
        int max = 0;
        
        for (int i = left + 1; i <= right; i++)
        {
            if (vec[i] - min > max)
                max = vec[i] - min;
            
            if (vec[i] < min)
                min = vec[i];
        }
        
        return max;
    }
};
