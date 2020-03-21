#include <iostream>
using namespace std;

int area[100][100] = { 0 };

int main()
{
	int num, l, b;
	int sum = 0;
	scanf("%d", &num);

	while (num--)
	{
		cin >> l >> b;
		for (int i = l; i < l + 10; i++)
		{
			for (int j = b; j < b + 10; j++)
			{
				area[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			sum += area[i][j];
		}
	}
	cout << sum << endl;


}