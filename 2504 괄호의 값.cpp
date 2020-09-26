#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<char> stack;
	string a;
	cin >> a;
	int s = 0, l = 0;
	int mul = 1, sum = 0;

	for (int i = 0; i < a.length(); i++)
	{
		char n = a[i];
		switch (n)
		{
		case '(':
			++s;
			mul *= 2;
			stack.push(n);
			if (i + 1 < a.length() && a[i + 1] == ')') {
				sum += mul;
			}
			if (i + 1 < a.length() && a[i + 1] == ']') {
				cout << 0 << endl;
				return 0;
			}
			break;
		case '[':
			++l;
			mul *= 3;
			stack.push(n);
			if (i + 1 < a.length() && a[i + 1] == ']')
				sum += mul;
			if (i + 1 < a.length() && a[i + 1] == ')') {
				cout << 0 << endl;
				return 0;
			}
			break;
		case ')':
			--s;
			if (s < 0)
			{
				cout << 0 << endl;
				return 0;
			}
			stack.pop();
			mul /= 2;
			break;
		case ']':
			--l;
			if (l < 0)
			{
				cout << 0 << endl;
				return 0;
			}
			stack.pop();
			mul /= 3;
			break;
		}
		if (stack.size() < 0)
		{
			cout << 0 << endl;
			return 0;
		}

	}
	if (stack.size() != 0 || l != 0 || s != 0)
		cout << 0 << endl;
	else
		cout << sum << endl;

	return 0;
}