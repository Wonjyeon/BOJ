#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9] = { 0, };
int list[9];
bool visited[9] = { 0, };

void func(int s, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	bool check[10000] = { 0, };

	for (int i = s; i < N; i++) {
		if (!check[list[i]] && !visited[i]) {
			visited[i] = true;
			check[list[i]] = true;
			arr[cnt] = list[i];
			func(i, cnt + 1);
			visited[i] = false;
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
	func(0, 0);
}