#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	set<string> people;
	string name, cmd;

	while (N--)
	{
		cin >> name >> cmd;
		if (cmd == "enter")
			people.insert(name);
		else
			people.erase(name);
	}
	for (auto it = people.rbegin(); it != people.rend(); it++)
	{
		cout << *it << "\n";
	}
}