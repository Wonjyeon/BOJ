#include <iostream>
using namespace std;

int main()
{
	int N;
	int arr[2][66];
	cin >> N;
	int max = -1;
	int t1, t2;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[0][i] >> arr[1][i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (arr[0][j] < arr[0][j + 1])
			{
				t1 = arr[0][j];
				arr[0][j] = arr[0][j + 1];
				arr[0][j + 1] = t1;

				t2 = arr[1][j];
				arr[1][j] = arr[1][j + 1];
				arr[1][j + 1] = t2;
			}
			else if (arr[0][j] == arr[0][j + 1] && arr[1][j] > arr[1][j + 1])
			{
				t1 = arr[0][j];
				arr[0][j] = arr[0][j + 1];
				arr[0][j + 1] = t1;

				t2 = arr[1][j];
				arr[1][j] = arr[1][j + 1];
				arr[1][j + 1] = t2;
			}
		}
	}

	int num = arr[0][4];
	int tot = 0;
	for (int i = 5; i < N; i++)
	{
		if (arr[0][i] == num)
			tot++;
		else if (arr[0][i] != num)
			break;
	}
	cout << tot << endl;
	return 0;
}