#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9] = { 0, };
int list[9];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	bool check[10000] = { 0, };

	for (int i = 0; i < N; i++) {
		if (!check[list[i]]) {
			check[list[i]] = true;
			arr[cnt] = list[i];
			func(cnt + 1);
		}

	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &list[i]);
	}
	sort(list, list + N);
	func(0);
}