#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
int N, Min = INF, people[11], visit[11];
vector<int> connect[11];

bool Conn(vector<int> v, int flag) {
	int check[11] = { 0, };
	int cnt = 1;
	queue<int> q;
	check[v[0]] = 1;
	q.push(v[0]);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < connect[x].size(); i++) {
			int nx = connect[x][i];
			if (check[nx] || visit[nx] != flag) continue;
			check[nx] = 1;
			q.push(nx);
			cnt++;
		}
	}
	if (cnt == v.size()) return true;
	return false;
}

void dfs(int idx, int cnt) {
	if (cnt >= 1) {
		vector<int> left, right;
		for (int i = 1; i <= N; i++) {
			if (visit[i])
				left.push_back(i);
			else
				right.push_back(i);
		}
		if (left.size() == 0 || right.size() == 0)
			return;
		if (Conn(left, 1) && Conn(right, 0)) {
			int l_sum = 0, r_sum = 0;
			for (int i = 1; i <= N; i++) {
				if (visit[i] == 1)
					l_sum += people[i];
				else
					r_sum += people[i];
			}
			Min = min(Min, abs(l_sum - r_sum));
		}
	}
	for (int i = idx; i <= N; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		dfs(i, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> people[i];
	for (int i = 1; i <= N; i++) {
		int t, a;
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> a;
			connect[i].push_back(a);
		}
	}
	dfs(1, 0);
	if (Min == INF) Min = -1;
	cout << Min << '\n';
}