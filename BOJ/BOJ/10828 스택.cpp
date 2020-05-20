#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int num;
	cin >> num;

	stack<int> stack;
	string cmd;

	while (num--)
	{
		cin >> cmd;

		if (cmd == "push")
		{
			int n;
			cin >> n;
			stack.push(n);
		}
		else if (cmd == "pop")
		{
			if (!stack.empty())
			{
				cout << stack.top() << endl;
				stack.pop();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (cmd == "size")
		{
			cout << stack.size() << endl;
		}
		else if (cmd == "empty")
		{
			if (stack.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (cmd == "top")
		{
			if (!stack.empty())
				cout << stack.top() << endl;
			else
				cout << -1 << endl;
		}
	}
}