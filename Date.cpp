#include <iostream>

using namespace std;

class Date
{
	friend ostream & operator<<(ostream &os, const Date &d);
	friend istream & operator>>(istream &is, Date &d);
	friend bool operator==(const Date &d1, const Date &d2);
	friend bool operator!=(const Date &d1, const Date &d2);
	friend bool operator>(const Date &d1, const Date &d2);
	friend bool operator<(const Date &d1, const Date &d2);
	friend bool operator>=(const Date &d1, const Date &d2);
	friend bool operator<=(const Date &d1, const Date &d2);
	friend int operator-(const Date &d1, const Date &d2);
public:
	Date(int year = 1990, int month = 1, int day = 1)
	: _year(year)
	, _month(month)
	, _day(day)
	{
		if (year < 1990)
			_year = 1990;
		if (month < 1 || month > 12 )
			_month = 1;
		if(!DayOfMonth(year, month, day))
				_day = 1;
	}
	Date(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date & operator++()
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};
		_day++;
		int day_of_month = days[_month];
		if (this->IsLeap() && 2 == _month)
			day_of_month++;
		if (_day > day_of_month)
		{
			_day = 1;
			_month++;	
		}
		if (_month > 12)
		{	
			_month = 1;
			_year++;
		}
		return *this;
	}
	Date & operator--()
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};	
		_day--;
		if (_day == 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day = days[_month];
			if (IsLeap() && 2 == _month)
					_day++;
		}
		return *this;
	}
	Date operator++(int)
	{
		Date old(*this);
		int days[] = {0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};
		_day++;
		int day_of_month = days[_month];
		if (this->IsLeap() && 2 == _month)
			day_of_month++;
		if (_day > day_of_month)
		{
			_day = 1;
			_month++;	
		}
		if (_month > 12)
		{	
			_month = 1;
			_year++;
		}
		return old;
	}
	Date operator--(int)
	{
		Date old(*this);
		int days[] = {0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};	
		_day--;
		if (_day == 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day = days[_month];
			if (IsLeap() && 2 == _month)
					_day++;
		}
		return old;
	
	}

	Date & operator=(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Date NDaysAgoOrAfter(int n)	//n天后日期
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};
		int i = n;
		Date ret(*this);
		if (n >= 0)
		{
			while (n--)
				++ret;
		}
		else
		{
			while (n++)
				--ret;
		}
		return ret;
	}
	bool IsLeap()
	{
		if ((_year%4 == 0 && _year%100 != 0) || (_year%400 == 0))
		{
			return true;
		}
		return false;
	}
	bool DayOfMonth(int year, int month, int day)
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};
		
		if (IsLeap() && 2 == month)
			days[month]++;
		if (day <= days[month] && day >= 1)
			return true;
		return false;
	}
	
private:
	int _year;
	int _month;
	int _day;
};
 
ostream & operator<<(ostream &os, const Date &d)
{
	os << d._year << "/" << d._month << "/" << d._day;
	return os;
}

istream & operator>>(istream &is, Date &d)
{
	is >> d._year >> d._month >> d._day;
	return is;
}

bool operator==(const Date &d1, const Date &d2)
{
	if (d1._year == d2._year)
		if (d1._month == d2._month)
			if (d1._day == d2._day)
				return true;

	return false;
}

bool operator!=(const Date &d1, const Date &d2)
{
	if (d1 == d2)
		return false;
	return true;
}



bool operator>(const Date &d1, const Date &d2)
{
	if (d1._year > d2._year)
		return true;
	else if (d1._year < d2._year)
		return false;
	else
	{
		if (d1._month > d2._month)
			return true;
		else if (d1._month < d2._month)
			return false;
		else
		{
			if (d1._day > d2._day)
				return true;
			else if (d1._day < d2._day)
				return false;
			else
				return true;
		}	
	}
}

bool operator<(const Date &d1, const Date &d2)
{
	if (d1 > d2 || d1 == d2)
		return false;
	return true;
}

bool operator>=(const Date &d1, const Date &d2)
{
	if (d1 > d2 && d1 == d2)
		return true;
	return false;
}

bool operator<=(const Date &d1, const Date &d2)
{
	if (d1 < d2 && d1 == d2)
		return true;
	return false;
}


int operator-(const Date &d1, const Date &d2)
{
	int SumDays = 0;
	int flag = 1;
	Date small, big;

	if (d1 > d2)
	{
		small = d2;
		big = d1;
	}
	else if (d1 < d2)
	{
		small = d1;
		big = d2;
		flag = -1;
	}
	else
		return 0;
	while (small < big)
	{
		SumDays++;
		++small;
	}
	return flag * SumDays;
}
int main()
{
	/*Date d1, d2;
	cout << d1 << endl << d2 << endl;
	cin >> d1 >> d2;
	cout << d1 << endl << d2 << endl;
	*/
	
	Date d1, d2(2016, 5, 30);
	d1 = d2.NDaysAgoOrAfter(-100);
	cout << "Now: " << d2 << endl << "100 Days Ago: " << d1 << endl;
	
	cout << d1 - d2 << endl;
	

	return 0;
}
