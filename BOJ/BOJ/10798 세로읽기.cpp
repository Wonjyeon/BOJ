#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

char sum[80];

int main()
{
	string str;
	int temp = 0;

	for (int i = 0; i < 5; i++)
	{
		temp = i;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			sum[temp] = str[j];
			temp += 5;
		}
	}
	for (int i = 0; i < 79; i++)
	{
		if (sum[i] != NULL)
		{
			printf("%c", sum[i]);
		}

	}
	printf("\n");

	return 0;
}