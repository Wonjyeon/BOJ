#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int *arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	printf("%d\n", arr[K - 1]);
	return 0;
}