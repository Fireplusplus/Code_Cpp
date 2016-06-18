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
	{
		pStr = new char[strlen(s.pStr) + 1];
		strcpy(pStr, s.pStr);
	}

	String & operator=(const String &s)
	{
		if (this != &s)
		{
			char *tmp = new char[strlen(s.pStr) + 1];
			strcpy(tmp, s.pStr);
			delete[] pStr;
			pStr = tmp;
		}
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

	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;

	return 0;
}
