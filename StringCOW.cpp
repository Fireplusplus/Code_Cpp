#include <iostream>
#include <string.h>

using namespace std;

class String
{
	friend ostream & operator<<(ostream &os, String &s);
	friend istream & operator>>(istream &is, String &s);
	friend bool operator>(const String &left, const String &right);
	friend bool operator<(const String &left, const String &right);
	friend bool operator==(const String &left, const String &right);
	friend bool operator!=(const String &left, const String &right);
	friend bool operator>=(const String &left, const String &right);
	friend bool operator<=(const String &left, const String &right);
public:
	String(const char *s = "\0")
	{
		if (NULL == s)
		{
			pStr = new char[1 + 4];
			*(int *)pStr = 1;
			pStr += 4;
			*pStr = '\0';
		}
		else
		{
			pStr = new char[strlen(s) + 1 + 4];
			*(int *)pStr = 1;
			pStr += 4;
			strcpy(pStr, s);
		}
	}

	String(const String &s)
	{
		pStr = s.pStr;
		++GetCnt();
	}

	String & operator=(const String &s)
	{
		if (pStr != s.pStr)
		{
			if(0 == --GetCnt())
				delete[] pStr;
			pStr = s.pStr;
			++GetCnt();
		}

		return *this;
	}
	
	char & operator[](int index)
	{
		if (GetCnt() > 1)
		{
			char *tmp = new char[strlen(pStr) + 1 + 4];
			*(int *)tmp = 1;
			tmp += 4;
			strcpy(tmp, pStr);
			--GetCnt();
			pStr = tmp;
		}
		return *(pStr + index);
	}
	size_t Size()
	{
		char *last = pStr;
		while (*last++)
			;
		last--;
		
		return last - pStr;
	}

	bool StrStr(const String &s)
	{
		char *p1 = pStr, *p2 = s.pStr;
		
		while (*p1)
		{
			if (*p1 == *p2)
			{
				char *str1 = p1, *str2 = p2;

				while (*p2 && *p2++ == *p1++)
					;
				if ('\0' == *p2)
					return true;
			}
			p1++;
		}
		return false;
	}

	size_t Copy(char *p, size_t pos, size_t count)
	{
		char *str = pStr + pos;
		int i = 0;

		while (*str && i < count)
		{
			*p++ = *str++; 
			i++;
		}
		size_t n = i;	
		while (i < count)
		{
			*p++ = '\0';
			i++;
		}
		return n;
	}

	~String()
	{
		--GetCnt();
		if (0 == GetCnt())
		{
			pStr -= 4;
			delete[] pStr;
		}
	}
	
private:
	int & GetCnt()
	{
		return *(int *)(pStr - 4);
	}

private:
	char *pStr;
};

ostream & operator<<(ostream &os, String &s)
{
	cout<<s.pStr;
	return os;
}

bool operator>(const String &left, const String &right)
{
	char *l = left.pStr;
	char *r = right.pStr;

	while (*l++ == *r++)
		;
	l--;
	r--;
	
	return *l > *r;
}

bool operator<(const String &left, const String &right)
{
	char *l = left.pStr;
	char *r = right.pStr;

	while (*l++ == *r++)
		;
	l--;
	r--;
	
	return *l < *r;
}

bool operator==(const String &left, const String &right)
{
	if (!(left > right) && !(left < right))
		return true;
	return false;
}

bool operator!=(const String &left, const String &right)
{
	if (left == right)
		return false;
	return true;
}

bool operator>=(const String &left, const String &right)
{
	if (left > right && left == right)
		return true;
	return false;
}

bool operator<=(const String &left, const String &right)
{
	if (left < right && left == right)
		return true;
	return false;
}

int main()
{
	/*String s1("s1");
	String s2(s1);
	String s3;
	s3 = s1;
	cout<<s3.Size()<<endl;
	cout<<s1<<endl<<s2<<endl<<s3<<endl;
	cout<<endl;
	s3[1] = '3';
	cout<<s1<<endl<<s2<<endl<<s3<<endl;
*/
	/*String s1("abcdabcabcde");
	String s2("abcdef");
	cout<<s1.StrStr(s2)<<endl;;
*/
	char p[10];
	String s("hello");
	int n = s.Copy(p, 1, 6);
	cout << p<< "  "<< n<< endl;
	
	return 0;
}
