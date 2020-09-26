#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int arr[100] = { 0 };
	int sum = 0;

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		sum += (arr[i] + 1) / 2;
	}
	if (sum >= N)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}