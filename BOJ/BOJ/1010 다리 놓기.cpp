#include <iostream>
#include <cstring>
using namespace std;

int T, N, M, d[31][31];

int Combination(int n, int r) {
	if (n == r || r == 0) return 1;
	if (d[n][r] >= 0) return d[n][r];
	return d[n][r] = Combination(n - 1, r) + Combination(n - 1, r - 1);
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << Combination(M, N) << '\n';
	}
	return 0;
}