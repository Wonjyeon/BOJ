#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int dwarf[9] = { 0 };
	int sum = 0;
	int i, j, a, b;
	int arr[7] = { 0 };


	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &dwarf[i]);
		sum += dwarf[i];
	}
	sum = sum - 100;

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (sum == dwarf[i] + dwarf[j])
			{
				a = i;
				b = j;
			}
		}
	}

	int temp1 = dwarf[a];
	int temp2 = dwarf[b];
	int temp;

	for (int k = 0; k < 9; k++)
	{
		for (int p = 0; p < 8 - k; p++)
		{
			if (dwarf[p] > dwarf[p + 1])
			{
				temp = dwarf[p];
				dwarf[p] = dwarf[p + 1];
				dwarf[p + 1] = temp;
			}
		}
	}

	for (int k = 0; k < 9; k++)
	{
		if (dwarf[k] == temp1 || dwarf[k] == temp2)
			continue;
		printf("%d\n", dwarf[k]);
	}
	return 0;
}