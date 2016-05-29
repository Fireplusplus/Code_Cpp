#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
public:
	Complex(int real = 0, int imag = 0)
	: _real(real)
	, _imag(imag)
	{
	}
	friend ostream & operator<<(ostream &_cout, const Complex &right);
	friend istream & operator>>(istream &_cin, Complex &right);
	
	friend bool operator>(const Complex &left, const Complex &right);
	friend bool operator<(const Complex &left, const Complex &right);
	friend bool operator==(const Complex &left, const Complex &right);
	
	friend Complex operator+(const Complex &left, const Complex &right);
	friend Complex operator-(const Complex &left, const Complex &right);
	
	Complex & operator=(const Complex & right)
	{
		_real = right._real;
		_imag = right._imag;

		return *this;
	}
	//~Complex() {}
private:
	int _real;
	int _imag;
};

ostream & operator<<(ostream &_cout, const Complex &right)
{
	cout << right._real;
	if (right._imag >= 0)
		cout << "+" << right._imag;
	else
		cout << "-" << right._imag;
	cout << "i";

	return _cout;
}

istream & operator>>(istream &_cin, Complex &right)
{
	cin>>right._real>>right._imag;
	
	return _cin;
}

bool operator>(const Complex &left, const Complex &right)
{
	long long l = sqrt((left._real * left._real + 
			left._imag * left._imag));
	long long r = sqrt((right._real * right._real + 
			right._imag * right._imag));
	return 	l > r;
}

bool operator<(const Complex &left, const Complex &right)
{
	long long l = sqrt((left._real * left._real + 
			left._imag * left._imag));
	long long r = sqrt((right._real * right._real + 
			right._imag * right._imag));
	return 	l < r;
}

bool operator==(const Complex &left, const Complex &right)
{
	long long l = sqrt((left._real * left._real + 
			left._imag * left._imag));
	long long r = sqrt((right._real * right._real + 
			right._imag * right._imag));
	return l == r;
}

Complex operator+(const Complex &left, const Complex &right)
{
	return Complex(left._real + right._real, left._imag + right._imag);
}

Complex operator-(const Complex &left, const Complex &right)
{
	return Complex(left._real - right._real, left._imag - right._imag);
}

int main()
{
	Complex c1, c2, c3;
	
	//cin >> c3;
	//c1 = c2 = c3;
	//cout << c1 << endl << c2 << endl << c3 << endl;
	
	cin >> c1 >> c2;
	cout << c1 << endl << c2 << endl;
	c3 = c1 + c2;
	cout << c3 << endl;
	/*if (c1 > c2)
		cout<< "c1 > c2" << endl;
	else if (c1 < c2)
		cout<< "c1 < c2" << endl;
	else
		cout<< "c1 == c2" << endl;
	*/
	


	return 0;
}
