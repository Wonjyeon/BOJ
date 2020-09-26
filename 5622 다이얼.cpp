#include <stdio.h>
#include <string.h>

int main()
{
	char str[15];
	int len;
	scanf("%s", str);
	len = strlen(str);
	int i = 0;
	int sum = 0;
	int cnt = 0;

	while (i<len)
	{
		switch (str[i])
		{
		case 'A':
		case 'B':
		case 'C':
			cnt = 3;
			break;

		case 'D':
		case 'E':
		case 'F':
			cnt = 4;
			break;

		case 'G':
		case 'H':
		case 'I':
			cnt = 5;
			break;

		case 'J':
		case 'K':
		case 'L':
			cnt = 6;
			break;

		case 'M':
		case 'N':
		case 'O':
			cnt = 7;
			break;

		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			cnt = 8;
			break;

		case 'T':
		case 'U':
		case 'V':
			cnt = 9;
			break;

		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			cnt = 10;
			break;
		}
		sum += cnt;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}