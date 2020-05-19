#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, a, b, arr[100001];
vector<int> v[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int i = 0; i < v[now].size(); i++) {
			arr[v[now][i]]--;
			if (arr[v[now][i]] == 0) q.push(v[now][i]);
		}
	}
	cout << '\n';
}