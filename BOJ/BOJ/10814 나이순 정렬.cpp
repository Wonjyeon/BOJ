#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1000000;
pair<int, pair<string, int>> people[MAX];

bool cmp(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
	{
		if (a.second.second < b.second.second)
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
		cin >> people[i].first >> people[i].second.first;
		people[i].second.second = i;
	}
	sort(people, people + N, cmp);

	for (int i = 0; i < N; i++)
	{
		cout << people[i].first << " " << people[i].second.first << "\n";
	}
}