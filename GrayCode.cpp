#include <iostream>
#include <vector>

using namespace std;

class GrayCode
{
public:
	vector<string> getGray(int n)
	{
		// write code here
		vector<string> v;
		v.push_back("0");
		v.push_back("1");

		Gray(v, n - 1);

		return v;
	}

	void Gray(vector<string>& v, int n)
	{
		if (0 == n)
			return;
		int size = v.size();
		
		for (int i = 0; i < size; i++)
		{
			v.push_back(v[i]);
		}

		for (int i = 0; i < size; i++)
		{
			v[i].insert(v[i].begin(), '0');
			v[size * 2 - i - 1].insert(v[size * 2 - i - 1].begin(), '1');
		}
		Gray(v, n - 1);
	}
};

int main()
{
	GrayCode g;
	vector<string> ret = g.getGray(2);

	return 0;
}