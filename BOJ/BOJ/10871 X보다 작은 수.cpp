#include <stdio.h>

int main() {
	int n, x, a;
	scanf("%d %d", &n, &x);
	while (n--)
	{
		scanf("%d", &a);
		if (a<x)
			printf("%d ", a);
	}
	return 0;
}
