#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int T, N;

	cin >> T;
	while (T--)
	{
		cin >> N;
		map<string, int> m;
		string cate;
		string str;

		int ans = 1;
		while (N--)
		{
			cin >> str >> cate;
			m[cate]++;
		}
		for (auto i = m.begin(); i != m.end(); i++)
		{
			ans *= i->second + 1;
		}
		ans--;
		cout << ans << endl;
	}
	return 0;
}