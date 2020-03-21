#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 200002;

int N, K, ans = 1;
int visit[200002];

int bfs(int sx) {
	int flag = 0;
	queue<int> q;
	q.push(sx);
	visit[sx] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();
			if (x - 1 == K || x + 1 == K || 2 * x == K)
			{
				flag = 1;
				return ans;
			}
			if (x - 1 >= 0 && !visit[x - 1]) {
				visit[x - 1] = 1;
				q.push(x - 1);
			}
			if (x + 1 <= MAX && !visit[x + 1]) {
				visit[x + 1] = 1;
				q.push(x + 1);
			}
			if (x * 2 <= MAX && !visit[2 * x]) {
				visit[2 * x] = 1;
				q.push(2 * x);
			}
		}
		ans++;
	}
}

int main() {
	cin >> N >> K;
	if (N > K) {
		ans = N - K;
	}
	else if (N == K)
		ans = 0;
	else
		ans = bfs(N);
	cout << ans << endl;
}