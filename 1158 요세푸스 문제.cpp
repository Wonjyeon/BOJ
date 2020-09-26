#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	queue<int> q;
	int arr[5001];
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int cnt = 1;
	int idx = 0;
	while (!q.empty()) {
		if (cnt == K) {
			arr[idx] = q.front();
			q.pop();
			cnt = 1;
			idx++;
		}
		else {
			int f = q.front();
			q.pop();
			q.push(f);
			cnt++;
		}
	}
	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			cout << arr[i] << ">" << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
	return 0;
}