#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	long long ans = 0;
	cin >> n;
	long long *arr = new long long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ans += arr[j] - arr[i];
		}
	}
	cout << 2 * ans << endl;
	return 0;
}