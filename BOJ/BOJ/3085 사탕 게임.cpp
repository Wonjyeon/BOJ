#include <iostream>
#include <algorithm>
using namespace std;

int N;
char arr[50][50];


int answer()
{
	int result = 1;

	for (int i = 0; i < N; i++)
	{
		int cnt = 1;

		for (int j = 1; j < N; j++)
		{
			if (arr[i][j - 1] == arr[i][j])
				cnt++;
			else
			{
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}

	for (int i = 0; i < N; i++)
	{
		int cnt = 1;

		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j + 1][i] == arr[j][i])
				cnt++;
			else
			{
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	return result;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(arr[i][j], arr[i][j + 1]);
			result = max(result, answer());
			swap(arr[i][j], arr[i][j + 1]);

			swap(arr[j + 1][i], arr[j][i]);
			result = max(result, answer());
			swap(arr[j + 1][i], arr[j][i]);
		}
	}
	cout << result << endl;
}

