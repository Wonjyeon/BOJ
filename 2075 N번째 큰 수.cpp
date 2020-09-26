#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	priority_queue<int> pq;
	int N, x;
	scanf("%d", &N);
	for (int i = 0; i < N*N; i++)
	{
		scanf("%d", &x);
		if (pq.size() < N)
			pq.push(-x);
		else
		{
			if (-pq.top() < x)
			{
				pq.pop();
				pq.push(-x);
			}
		}
	}
	printf("%d\n", -pq.top());
	return 0;
}