#include <iostream>
#include <string>
using namespace std;


int main()
{
	string N;
	cin >> N;
	int num;
	int max = 0;

	char cnt[10] = {};

	for (int i = 0; i < N.length(); i++) {
		cnt[(N[i] - 48)]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
		{
			continue;
		}
		if (cnt[i] > max)
			max = cnt[i];
	}

	int temp = (cnt[6] + cnt[9] + 1) / 2;
	if (temp > max)
		max = temp;

	cout << max << endl;
	return 0;
}