#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];
int parent[100001];
bool visit[100001];
int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < tree[x].size(); i++) {
			if (!visit[tree[x][i]]) {
				visit[tree[x][i]] = 1;
				parent[tree[x][i]] = x;
				q.push(tree[x][i]);
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}