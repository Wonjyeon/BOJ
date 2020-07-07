#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	string name;
	vector<string> v;
	set<string> s;
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	while (M--)
	{
		cin >> name;
		if (binary_search(v.begin(), v.end(), name))
		{
			s.insert(name);
		}
	}
	cout << s.size() << endl;
	for (auto it : s)
		cout << it << endl;
	return 0;
}