#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

int N, M;
int btn[10] = { 1,1,1,1,1,1,1,1,1,1 };

int possible(int c) {
	if (c == 0)
		return btn[c] ? 1 : 0;
	int len = 0;
	while (c) {
		if (!btn[c % 10]) return 0;
		len++;
		c /= 10;
	}
	return len;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int b;
	while (M--) {
		cin >> b;
		btn[b] = 0;
	}
	int ans = abs(N - 100);
	for (int i = 0; i < MAX; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0)
			ans = min(ans, len + abs(N - c));
	}
	cout << ans << '\n';
}