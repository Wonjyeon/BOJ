#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int a = 1;
	int sum = 0;

	while (1)
	{
		if (N < pow(10, a))
		{
			a -= 1;
			break;
		}
		else
			a++;
	}
	for (int i = 1; i <= a; i++)
	{
		sum += i * 9 * (pow(10, i - 1));
	}
	sum += (a + 1)*(N - pow(10, a) + 1);
	cout << sum;
	return 0;
}