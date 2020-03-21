#include <iostream>
using namespace std;

int N, M;
int arr[9] = { 0, };

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[cnt] = i;
		func(cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	func(0);
}