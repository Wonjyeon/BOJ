#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
pair<int, int> p[MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + N, cmp);

	for (int i = 0; i < N; i++)
	{
		cout << p[i].first << " " << p[i].second << "\n";
	}
	return 0;
}