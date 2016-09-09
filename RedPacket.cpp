/*
 * 题目描述
 * 春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过
 * 了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
 * 给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
 * 若没有金额超过总数的一半，返回0。 
 */

class Gift
{
public:
	int getValue(vector<int> gifts, int n)
	{
		// write code here
		if (n <= 0)
			return 0;

		int num = gifts[0];
		int cnt = 1;
		for (int i = 1; i < gifts.size(); i++)
		{
			if (num == gifts[i])
			{
				cnt++;
			}
			else
			{
				cnt--;
				if (cnt == 0)
				{
					num = gifts[i];
					cnt = 1;
				}
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (gifts[i] == num)
				cnt++;
		}
		if (cnt > n / 2)
			return num;
		return 0;
	}

};