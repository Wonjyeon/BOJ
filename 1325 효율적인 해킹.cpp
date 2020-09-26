#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 10001;
vector<int> v[MAX];
bool visit[MAX];
int N;
int cnt = 0;
int temp = 0;
int Max = -1;
set<int> s;

void dfs(int x)
{
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int nx = v[x][i];

		if (!visit[nx])
		{
			cnt++;
			dfs(nx);
		}
	}
}

int main()
{
	int idx[MAX];
	int M;
	scanf("%d %d", &N, &M);

	//�ŷ� ���� �Է� -> x y�� �ԷµǸ� x�� y�� �ŷ�
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(visit, false, sizeof(visit));
		cnt = 0;
		dfs(i);
		if (Max == cnt)
			s.insert(i);
		else if (cnt > Max)
		{
			s.clear();
			s.insert(i);
			Max = cnt;
		}
		cnt = 0;
	}
	for (auto it : s)
	{
		printf("%d ", it);
	}
	return 0;
}