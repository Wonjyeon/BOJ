#include <iostream>
using namespace std;

bool check[246913];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	check[1] = true;
	for (int i = 2; i < 246913; i++) {
		if (check[i]) continue;
		if (i < 500) {
			int tmp = i*i;
			for (tmp; tmp < 246913; tmp += i) {
				check[tmp] = true;
			}
		}
	}
	while (1) {
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!check[i])
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}