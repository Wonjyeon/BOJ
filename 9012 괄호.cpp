#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int left, right, flag, last;
	string a;

	while (num--)
	{
		cin >> a;
		left = 0;
		right = 0;
		flag = 0;

		last = a.length() - 1;
		if (a[0] == ')' || a[last] == '(')
		{
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0; i <a.length(); i++)
		{
			if (a[i] == '(')
				left++;
			else if (a[i] == ')')
				right++;
			if (right > left)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			cout << "NO" << endl;
			continue;
		}
		else
		{
			if (left == right)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}