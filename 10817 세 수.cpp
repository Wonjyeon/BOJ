#include <stdio.h>

int main()
{
	int n1, n2, n3;
	int max, min, mid;

	scanf("%d %d %d", &n1, &n2, &n3);

	if ((n1 >= n2&&n1 <= n3) || (n1 >= n3&&n1 <= n2))
		printf("%d\n", n1);
	else if ((n2 >= n1&&n2 <= n3) || (n2 >= n3&&n2 <= n1))
		printf("%d\n", n2);
	else
		printf("%d\n", n3);
	return 0;
}