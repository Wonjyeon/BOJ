#include <iostream>
using namespace std;

int h[1000] = { 0 };
int a[1000] = { 0 };

int main()
{
	int N, M;
	int max1 = 0;
	int max2 = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
		if (max1 < h[i])
			max1 = h[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a[i];
		if (max2 < a[i])
			max2 = a[i];
	}
	cout << max1 + max2 << endl;

	return 0;
}