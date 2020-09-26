#include <stdio.h>

int main()
{
	int cnt = 0, num1 = 0, num2 = 0;
	scanf("%d", &cnt);
	int sum = 0;

	for (int i = 0; i < cnt; i++)
	{
		scanf("%d %d", &num1, &num2);
		sum = num1 + num2;
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}