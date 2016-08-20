#include <iostream>
#include <vector>
using namespace std;

void PrintMax(vector<size_t> &g, size_t a, size_t b)
{
	size_t max = 0;
	for (size_t i = a - 1; i < g.size() && i < b; i++)
	{
		if (g[i] > max)
			max = g[i];
	}
	cout << max << endl;
}

void update(vector<size_t> &g, size_t a, size_t b)
{
	if (a > g.size())
		return;
	g[a - 1] = b;
}

int main()
{
	vector<size_t> grade;
	size_t n, m;
	cin >> n >> m;
	size_t i = 0;
	while (i < n)
	{
		int tmp;
		cin >> tmp;
		grade.push_back(tmp);
		i++;
	}

	char c;
	size_t a, b;
	i = 0;
	while (i < m)
	{
		cin >> c;
		cin >> a >> b;

		if (c == 'Q')
			PrintMax(grade, a, b);
		else
			update(grade, a, b);
		i++;
	}

	return 0;
}