#include <iostream>
using namespace std;

int main()
{
	int num, temp, sum = 0;
	int A[50];
	int B[50];
	int seq2[50];

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &B[i]);
		seq2[i] = B[i];
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (seq2[j] > seq2[j + 1])
			{
				temp = seq2[j];
				seq2[j] = seq2[j + 1];
				seq2[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		sum += A[num - i - 1] * seq2[i];
	}
	printf("%d\n", sum);
	return 0;
}