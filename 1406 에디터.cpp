#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> left;
	stack<char> right;

	string str;
	int num;

	cin >> str;
	cin >> num;

	for (int i = 0; i < str.length(); i++)
	{
		left.push(str[i]);
	}

	while (num--)
	{
		char cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;

		case 'D':
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;

		case 'B':
			if (!left.empty())
				left.pop();
			break;

		case 'P':
			char c;
			cin >> c;
			left.push(c);
			break;
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		printf("%c", right.top());
		right.pop();
	}
	return 0;
}