#include <stdio.h>
#include <string.h>

int main()
{
	int num[26];
	char str[1000000];

	int max, len, cnt, ans = 0, k;

	scanf("%s", str);
	len = strlen(str);

	for (int i = 65; i < 91; i++)
	{
		cnt = 0;
		for (int j = 0; j < len; j++)
		{
			if (str[j] == i || str[j] == i + 32)
				cnt++;
		}
		num[i - 65] = cnt;
	}
	max = num[0];
	for (int i = 0; i < 26; i++)
	{
		if (num[i] > max)
			max = num[i];
	}
	for (int i = 0; i < 26; i++)
	{
		if (num[i] == max)
		{
			ans++;
			k = i;
		}
	}
	if (ans == 1)
		printf("%c\n", k + 65);
	else if (ans > 1)
		printf("?\n");
	return 0;
}