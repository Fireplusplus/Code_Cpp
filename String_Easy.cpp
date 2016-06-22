#include <iostream>
#include <string.h>

using namespace std;

class String
{
	friend ostream & operator<<(ostream &os, String &s);

public:
	String(const char *s = "\0")
	{
		if (NULL == s)
		{
			pStr = new char[1];
			*pStr = '\0';
		}
		else
		{
			pStr = new char[strlen(s) + 1];
			strcpy(pStr, s);
		}
	}
	
	String(const String &s)
	: pStr(NULL)
	{
		String tmp(s.pStr);
		std::swap(pStr, tmp.pStr);
	}

	String & operator=(String s)
	{
		std::swap(pStr, s.pStr);
		return *this;
	}

	~String()
	{
		delete[] pStr;
		pStr = NULL;
	}
private:
	char *pStr;
};

ostream & operator<<(ostream &os, String &s)
{
	os << s.pStr;
	return os;
}

int main()
{
	String s1;
	String s2("s2");
	String s3(s2);
	s1 = s3;

	cout << s1<< endl;
	cout << s2<< endl;
	cout << s3<< endl;

	return 0;
}
