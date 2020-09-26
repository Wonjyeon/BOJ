#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int num;
	cin >> num;

	queue<int> queue;
	string cmd;

	while (num--)
	{
		cin >> cmd;

		if (cmd == "push")
		{
			int n;
			cin >> n;
			queue.push(n);
		}
		else if (cmd == "pop")
		{
			if (!queue.empty())
			{
				cout << queue.front() << endl;
				queue.pop();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (cmd == "size")
		{
			cout << queue.size() << endl;
		}
		else if (cmd == "empty")
		{
			if (queue.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (cmd == "front")
		{
			if (!queue.empty())
				cout << queue.front() << endl;
			else
				cout << -1 << endl;
		}
		else if (cmd == "back")
		{
			if (!queue.empty())
				cout << queue.back() << endl;
			else
				cout << -1 << endl;
		}
	}
	return 0;
}