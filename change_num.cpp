/* 输入n个数，请将其中的偶数的二进制反转。 */

#include <iostream>

using namespace std;

int change(int n)
{
	int ret = 0;

	while (n != 1)
	{
		ret = 2 * ret + n % 2;
		n /= 2;
	}

	return ret * 2 + 1;
}

int main()
{
	int n;
	int num;
	cin >> n;

	while (n--)
	{
		cin >> num;
		if ((num & 1) == 1)
			printf("%d ", num);
		else
			cout << change(num) << " ";

	}

	return 0;
}