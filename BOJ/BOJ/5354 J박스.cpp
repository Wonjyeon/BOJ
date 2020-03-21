#include <iostream>
using namespace std;

int main()
{
	int tCase, box;
	scanf("%d", &tCase);

	while (tCase--)
	{
		scanf("%d", &box);
		for (int i = 1; i <= box; i++)
		{
			if (i == 1 || i == box)
			{
				for (int j = 1; j <= box; j++)
				{
					printf("#");
				}
				printf("\n");
			}
			else
			{
				printf("#");
				for (int j = 1; j <= box - 2; j++)
				{
					printf("J");
				}
				printf("#\n");
			}
		}
		printf("\n");
	}
}