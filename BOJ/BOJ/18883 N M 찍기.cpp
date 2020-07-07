#include <iostream>
using namespace std;

int main() {
	int N, M, cnt = 0, num = 0;
	cin >> N >> M;
	num = N*M;
	for (int i = 1; i <= num; i++) {
		cout << i;
		cnt++;
		if (cnt == M) {
			cout << '\n';
			cnt = 0;
		}
		else cout << ' ';
	}
	return 0;
}