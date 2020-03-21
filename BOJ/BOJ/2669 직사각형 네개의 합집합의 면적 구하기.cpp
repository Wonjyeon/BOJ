#include <iostream>
using namespace std;

int main()
{
	int area[100][100] = { 0 };

	int num = 4;
	int lx, ly, rx, ry;
	int sum = 0;
	while (num--)
	{
		cin >> lx >> ly >> rx >> ry;

		for (int i = lx; i < rx; i++)
		{
			for (int j = ly; j < ry; j++)
			{
				area[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++) {
			sum += area[i][j];
		}
	}

	printf("%d", sum);
}