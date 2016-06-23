#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class String
{
	friend ostream & operator<<(ostream &os, String &s);

public:
	String(const char *s = "\0")
	: pCnt(new int(1))
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

	String(String &s)
	: pCnt(s.pCnt)
	, pStr(s.pStr)
	{
		(*pCnt)++;
	}

	String & operator=(String &s)
	{
		if (pCnt != s.pCnt)
		{
			(*pCnt)--;
			if (0 == *pCnt)
			{	
				delete pCnt;
				delete[] pStr;
			}
			pCnt = s.pCnt;
			(*pCnt)++;
			pStr = s.pStr;
		}
		return *this;
	}

	~String()
	{
		assert(NULL != pCnt && NULL != pStr);
		(*pCnt)--;
		if (0 == *pCnt)
		{
			delete pCnt;
			pCnt = NULL;
			delete[] pStr;
			pStr = NULL;
		}
	}

private:
	char *pStr;
	int *pCnt;
};

ostream & operator<<(ostream &os, String &s)
{
	os << s.pStr<<" 引用计数:"<< *(s.pCnt);
	return os;
}

int main()
{
	String s1("s1");
	String s2(s1);
	String s3 = s2;

	cout << s1<< endl<< s2<< endl<< s3<< endl;
	String s4("s4");
	s1 = s4;
	cout<<endl;
	cout << s1<< endl<< s2<< endl<< s3<< endl<< s4<< endl;

	String s7;
	String s8;
	s7 = s8;
	return 0;
}
