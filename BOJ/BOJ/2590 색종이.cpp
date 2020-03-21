#include <iostream>
using namespace std;

int main()
{
	int arr[7] = { 0 };
	for (int i = 1; i < 7; i++)
		cin >> arr[i];

	int sum = arr[6] + arr[5] + arr[4] + arr[3] / 4;

	arr[1] -= arr[5] * 11;
	arr[2] -= arr[4] * 5;

	if (arr[3] % 4 != 0)
	{
		sum++;
		arr[3] %= 4;
		arr[1] -= 8 - arr[3];
		arr[2] -= (4 - arr[3]) * 2 - 1;
	}
	if (arr[2] > 0)
	{
		sum += ((arr[2] - 1) / 9) + 1;
		if (arr[2] % 9 != 0)
			arr[1] -= 4 * (9 - ((arr[2]) % 9));
	}
	else
		arr[1] += 4 * arr[2];

	if (arr[1] > 0)
		sum += (arr[1] - 1) / 36 + 1;

	cout << sum << endl;
}