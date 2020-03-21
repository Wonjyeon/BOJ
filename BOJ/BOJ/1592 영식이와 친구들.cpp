#include <iostream>
using namespace std;

int arr[100];

int main() {
	ios::sync_with_stdio; cin.tie(0);
	int N, M, L;
	int cnt = 0;

	cin >> N >> M >> L;
	int now_idx = 0;
	while (1) {
		arr[now_idx]++;
		if (arr[now_idx] == M)
			break;
		if (arr[now_idx] % 2 == 1) {
			now_idx = (now_idx + L) % N;
		}
		else {
			now_idx -= L;
			if (now_idx < 0)
				now_idx = N + now_idx;
		}
		cnt++;
	}
	cout << cnt << endl;

}