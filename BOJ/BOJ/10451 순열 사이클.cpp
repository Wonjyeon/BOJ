#include <iostream>
#include <queue>
using namespace std;

int map[1001];
bool visit[1001];
queue<int> q;

void dfs(int x)
{
	visit[x] = true;
	q.push(x);
	int nx = map[x];
	if (!visit[nx])
		dfs(nx);
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		int cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> map[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				cnt++;
				dfs(i);
			}
		}
		for (int i = 1; i <= N; i++)
		{
			map[i] = 0;
			visit[i] = false;
		}
		cout << cnt << endl;
	}
}