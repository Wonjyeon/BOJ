#include <stdio.h>
#include <string.h>	

int main()
{
	int wordnum = 0;
	int cnt = 0;
	int length = 0;
	int isWord = 0;

	char str[100] = { 0, };
	char str1[100] = { 0, };

	scanf("%d", &wordnum);

	while (wordnum > 0)
	{
		isWord = 0;
		scanf("%s", str);
		length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			str1[i] = str[i];
			if (str1[i] != str[i + 1])
			{
				for (int j = i + 1; j < length; j++)
				{
					if (str[j] == str1[i])
						isWord = 1;
				}
			}
		}
		if (isWord == 0)
			cnt++;
		wordnum--;
	}
	printf("%d\n", cnt);
	return 0;
}