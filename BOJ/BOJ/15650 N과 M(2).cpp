#include <iostream>
using namespace std;

int N, M;
int arr[9] = { 0, };
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
	for (int i = s; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			func(i, cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	func(1, 0);
}