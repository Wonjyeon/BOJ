#include <iostream>
using namespace std;

int N, M;
int arr[9] = { 0, };

void func(int s, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = s; i <= N; i++) {
		arr[cnt] = i;
		func(i, cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	func(1, 0);
	return 0;
}