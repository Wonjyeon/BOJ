#include <iostream>
using namespace std;

int M, N, visit[1000001];

int main() {
	cin >> M >> N;
	for (int i = 2; i <= N; i++) {
		if (visit[i] == 0) {
			if (i >= M)
				cout << i << '\n';
			if (i >= 1000) continue;
			long long tmp = i*i;
			for (tmp; tmp <= N; tmp += i) {
				visit[tmp] = 1;
			}
		}
	}
	return 0;
}