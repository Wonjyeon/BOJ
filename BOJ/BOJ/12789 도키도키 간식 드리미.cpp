#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	queue<int> q;
	stack<int> wait;

	int N;

	scanf("%d", &N);
	for (int i = 0; i< N; i++)
	{
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}
	int start = 1;
	while (!q.empty() || !wait.empty())
	{
		if (!q.empty() && q.front() == start)
		{
			start++;
			q.pop();
			continue;
		}
		if (!wait.empty() && wait.top() == start)
		{
			start++;
			wait.pop();
			continue;
		}
		if (q.empty())
		{
			printf("Sad");
			return 0;
		}
		wait.push(q.front());
		q.pop();
	}
	printf("Nice");
	return 0;
}