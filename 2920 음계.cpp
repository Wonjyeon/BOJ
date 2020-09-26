#include <stdio.h>

int main()
{
	int arr[8];
	int as = 0, ds = 0, mix = 0;

	for (int i = 0; i<8; i++)
	{
		scanf("%d", &arr[i]);

		if (i + 1 == arr[i])
			as++;
		else if (8 - i == arr[i])
			ds++;
		else
			mix++;
	}

	if (as == 8)
		printf("ascending\n");
	else if (ds == 8)
		printf("descending\n");
	else
		printf("mixed\n");
	return 0;
}