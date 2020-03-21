#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int n;

	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		s.insert(n % 42);
	}
	cout << s.size() << endl;
}