#include <iostream>

using namespace std;

int Add(int left, int right)
{
	int sum = left, carry = right;
	do
	{
		sum = left ^ right;
		carry = (left & right) << 1;
	} while (carry > 0);

	return sum;
}

int main()
{
	int ret = Add(12, 17);
	cout << ret << endl;

	return 0;
}
