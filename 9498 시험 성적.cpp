#include <stdio.h>

int main()
{
	int grade = 0;
	scanf("%d", &grade);

	if (90 <= grade&&grade <= 100)
		printf("A\n");
	else if (80 <= grade&&grade <= 89)
		printf("B\n");
	else if (70 <= grade&&grade <= 79)
		printf("C\n");
	else if (60 <= grade&&grade <= 69)
		printf("D\n");
	else
		printf("F\n");
	return 0;
}