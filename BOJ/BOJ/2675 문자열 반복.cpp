#include <stdio.h>

int main()
{
	int tn = 0;
	int num = 0;
	char str[21] = { 0, };
	scanf("%d", &tn);

	while (tn > 0)
	{
		scanf("%d", &num);
		scanf("%s", str);

		for (int i = 0; i < str[i]; i++)
		{
			int p = num;
			while (p > 0)
			{
				printf("%c", str[i]);
				p--;
			}
		}
		tn--;
		printf("\n");
	}


}