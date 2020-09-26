#include <stdio.h>

int main()
{
	int length = 0, sum = 0;
	char num[100] = { 0, };

	scanf("%d", &length);
	scanf("%s", num);

	for (int i = 0; i < length; i++)
		sum += num[i] - '0';
	printf("%d", sum);
	return 0;
}