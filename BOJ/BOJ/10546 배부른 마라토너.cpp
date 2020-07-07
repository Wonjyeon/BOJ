#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<string, int>> v;
	map<string, int> mp;
	int idx = 0;

	for (int i = 0; i < 2 * N - 1; i++)
	{
		string name;
		cin >> name;
		if (!mp.count(name))
		{
			mp[name] = idx++;
			v.push_back({ name,1 });
		}
		else
			v[mp[name]].second++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second % 2 != 0) {
			cout << v[i].first << "\n";
			break;
		}
	}
	return 0;
}