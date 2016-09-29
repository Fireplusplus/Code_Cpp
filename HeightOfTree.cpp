/*
 * 现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
 * 输入
 * 输入的第一行表示节点的个数n（1<=n<=1000，节点的编号为0到n-1）组成，
 * 下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
 * 输出
 * 输出树的高度，为一个整数
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> father(n - 1);
	vector<int> child(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> father[i] >> child[i];
	}

	vector<int> height(n);
	height[0] = 1;
	for (int i = 0; i < n-1; i++)
	{
		height[i+1] = height[father[i]] + 1;
	}
	int max = height[0];
	for (int i = 1; i < n; i++)
		if (max < height[i])
			max = height[i];
	cout << max << endl;

	return 0;
}