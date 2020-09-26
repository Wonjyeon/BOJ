#include <iostream>
#include <set>
using namespace std;

int main()
{
	char cmd;
	int T, K, num;
	cin >> T;
	while (T--)
	{
		multiset<int> s;
		cin >> K;
		while (K--)
		{
			cin >> cmd >> num;
			if (cmd == 'I')
				s.insert(num);
			else if (cmd == 'D'&&s.size()>0)
			{
				if (num == -1)
					s.erase(s.begin());
				else
				{
					auto it = s.end();
					it--;
					s.erase(it);
				}
			}
		}
		if (s.size() == 0)
			cout << "EMPTY\n";
		else
		{
			auto it = s.end();
			it--;
			cout << *it << " " << *s.begin() << "\n";
		}
	}
	return 0;
}