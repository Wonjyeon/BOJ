#include <stdio.h>

int main()
{
	char str[1000001];
	int count = 0;
	int isSpace = 1;

	scanf("%[^\n]s", str);

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			isSpace = 1;
		else if (isSpace)
		{
			isSpace = 0;
			count++;
		}
	}
	printf("%d\n", count);
}