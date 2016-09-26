/*
 * 一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都有一个弹簧，
 * 袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，
 * 就代表袋鼠下一跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，
 * 要跳到最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出-1
 * 输入
 * 输入分两行，第一行是数组长度N，第二行是每一项的值，用空格分隔
 * 输出
 * 输出最少的跳数，无法到达输出-1
 */

#include <iostream>
#include <vector>

using namespace std;

int Judge(vector<int> arr)
{
	vector<int> cnt(arr.size() + 1, 0);	//当前最少跳数

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0 && (cnt[i] != 0 || i == 0))	// 当前柱子可以到达
		{
			for (int j = i + 1; j <= arr[i] + i && j < cnt.size(); j++)
			{
				int n = cnt[i] + 1;
				if (n < cnt[j] || cnt[j] == 0)
					cnt[j] = n;
			}
		}
	}

	if (cnt.back() != 0)
		return cnt.back();
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ret = Judge(arr);
	cout << ret << endl;

	return 0;
}