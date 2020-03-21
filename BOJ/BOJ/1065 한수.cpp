#include <iostream>
using namespace std;

int main()
{
	int N, ans, a, b, c;
	cin >> N;
	if (N < 100)
		ans = N;
	else
	{
		ans = 99;
		for (int i = 100; i <= N; i++)
		{
			a = i % 10;
			b = (i / 10) % 10;
			c = (i / 100);

			if ((a - b) == (b - c))
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}