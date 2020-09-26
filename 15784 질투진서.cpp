#include <iostream>
using namespace std;

int arr[1000][1000] = { 0 };

int main()
{
	int N, a, b, c, d;
	int flag = 0;

	cin >> N >> a >> b;
	c = a - 1;
	d = b - 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int num = arr[c][d];
	for (int i = 0; i < N; i++)
	{
		if (i != d && arr[c][i] > num || i != c &&arr[i][d]>num)
		{
			cout << "ANGRY" << endl;
			return 0;
		}
	}
	cout << "HAPPY" << endl;
	return 0;
}