/* 
 * 1、除了最高位（左边第一位），格雷码的位元完全上下对称。
 * 比如第一个格雷码与最后一个格雷码对称（除了第一位），
 * 第二个格雷码与倒数第二个对称，以此类推。
 * 2、最小的重复单元是 0 , 1。
 */

#include <iostream>
#include <math.h>

using namespace std;

string * GrayCode(int n)
{
	string * graycode = new string[(int)pow(2, n)];

	if (1 == n)
	{
		graycode[0] = "0";
		graycode[1] = "1";
		return graycode;
	}

	string* tail = GrayCode(n - 1);

	for (int i = 0; i < (int)pow(2, n-1); i++)
	{
		graycode[i] = "0" + tail[i];
		graycode[(int)pow(2, n)- i - 1] = "1" + tail[i];
	}
	
	return graycode;
}

int main()
{
	string *str = GrayCode(3);

	for (int i = 0; i < 8; i++)
	{
		cout<<str[i]<<endl;;
	}

	return 0;
}
