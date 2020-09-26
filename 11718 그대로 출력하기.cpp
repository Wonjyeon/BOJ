#include <stdio.h>
int main()
{
	char a[200];
	while (scanf("%[^\n]s", a) != -1)
	{
		getchar();
		printf("%s\n", a);
	}
	return 0;
}