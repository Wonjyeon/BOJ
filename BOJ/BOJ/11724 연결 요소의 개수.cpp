#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
bool visit[MAX];
int N, M;

void dfs(int x)
{
	visit[x] = true;
	for (int y : graph[x])
	{
		if (!visit[y])
			dfs(y);
	}
}

int main()
{
	int cnt = 0;
	cin >> N >> M;
	int s, e;
	while (M--)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}