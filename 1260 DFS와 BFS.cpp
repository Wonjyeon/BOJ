#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
queue<int> Q;
bool visit[MAX];

void dfs(int x)
{
	visit[x] = true;
	printf("%d ", x);

	for (int y : adj[x])
	{
		if (!visit[y])
			dfs(y);
	}
}

void bfs(int sx)
{
	Q.push(sx);
	visit[sx] = true;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		printf("%d ", x);

		for (int y : adj[x])
		{
			if (!visit[y])
			{
				Q.push(y);
				visit[y] = true;
			}
		}
	}
}

int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	while (m--)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	puts("");
	memset(visit, 0, sizeof(visit));
	bfs(v);
	puts("");
	return 0;
}