#include <stdio.h>

int main()
{
	int num1, num2, a, b;
	int f, m, l;

	scanf("%d %d", &num1, &num2);

	f = num1 / 100;
	m = (num1 / 10) % 10;
	l = num1 % 10;

	a = f + 10 * m + 100 * l;

	f = num2 / 100;
	m = (num2 / 10) % 10;
	l = num2 % 10;


	b = f + 10 * m + 100 * l;

	if (a > b)
		printf("%d\n", a);
	else if (b > a)
		printf("%d\n", b);
}