#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, temp, sum;
	cin >> N;
	int m = N;

	for (int i = 1; i < N; i++)
	{
		temp = i;
		sum = i;
		while (temp > 0)
		{
			sum += temp % 10;
			temp = temp / 10;
		}
		if (sum == N)
			m = min(m, i);
	}
	if (m == N)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << m << endl;
	}
	return 0;
}