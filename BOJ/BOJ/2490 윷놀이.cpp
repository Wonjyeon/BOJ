#include <iostream>
using namespace std;

//A : 3, B : 2, C : 1, D: 0, E : 4

int main()
{
	int n = 3;
	int sum = 0;
	int play;
	while (n--)
	{
		for (int i = 0; i < 4; i++)
		{

			scanf("%d", &play);
			sum += play;
		}
		switch (sum)
		{
		case 0:
			printf("D\n");
			break;
		case 1:
			printf("C\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 3:
			printf("A\n");
			break;
		case 4:
			printf("E\n");
			break;
		}
		sum = 0;
	}

}