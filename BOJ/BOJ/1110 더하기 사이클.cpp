#include <iostream>
using namespace std;

int main()
{
	int N = 2;
	int num = 0;
	int sum = 0;
	int arr[1000];
	cin >> num;
	if (num < 10)
	{
		arr[0] = 0;
		arr[1] = num;
	}
	else
	{
		arr[0] = num / 10;
		arr[1] = num % 10;
	}
	while (1)
	{
		sum = arr[N - 2] + arr[N - 1];
		N++;
		if (sum >= 10)
			sum = sum % 10;
		arr[N - 1] = sum;
		if (arr[N - 2] == arr[0] && arr[N - 1] == arr[1])
		{
			cout << N - 2 << endl;
			return 0;
		}
	}

}