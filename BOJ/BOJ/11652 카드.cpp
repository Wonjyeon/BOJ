#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000000] = { 0 };


int main()
{
	int N;
	int cnt = 1;
	int max_cnt = 1;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	long long ans = arr[0];

	for (int i = 1; i < N; i++)
	{
		if (arr[i] == arr[i - 1])
			cnt++;
		else
			cnt = 1;
		if (max_cnt < cnt)
		{
			max_cnt = cnt;
			ans = arr[i];
		}
	}
	cout << ans << endl;
}