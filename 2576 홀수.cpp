#include <iostream>
using namespace std;

int main()
{
	int num;
	int min = 100;
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		if (num % 2 == 1)
		{
			sum += num;
			if (num < min)
				min = num;
		}
	}
	if (sum == 0)
	{
		cout << -1 << endl;
	}
	else {
		cout << sum << endl << min << endl;
	}
	return 0;
}