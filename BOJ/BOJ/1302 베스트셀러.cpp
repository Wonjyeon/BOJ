#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	map<string, int> m;
	int Max = -1;
	while (N--)
	{
		string name;
		cin >> name;
		m[name]++;
	}
	for (auto i = m.begin(); i != m.end(); i++)
	{
		Max = max(Max, i->second);
	}
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (i->second == Max)
		{
			cout << i->first << "\n";
			return 0;
		}
	}
}