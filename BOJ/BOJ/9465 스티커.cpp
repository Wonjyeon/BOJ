#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, T, s[2][1000001], d[2][1000001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> N;
		for (int i = 0; i < 2; i++) 
			for (int j = 1; j <= N; j++) 
				cin >> s[i][j];
		d[0][1] = s[0][1], d[1][1] = s[1][1];
		for (int i = 2; i <= N; i++) {
			d[0][i] = max(d[1][i - 2] + s[0][i], d[1][i - 1] + s[0][i]);
			d[1][i] = max(d[0][i - 2] + s[1][i], d[0][i - 1] + s[1][i]);
			ans = max(d[0][i], ans);
			ans = max(d[1][i], ans);
		}
		cout << ans << '\n';
	}
}