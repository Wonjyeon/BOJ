#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int s[2][1000001] = { 0, };
int d[2][1000001] = { 0, };
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		int Max = 0;
		memset(s, 0, sizeof(s));
		memset(d, 0, sizeof(d));
		cin >> N;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= N; j++)
				cin >> s[i][j];
		for (int i = 1; i <= N; i++) {
			d[0][i] = max(d[1][i - 1] + s[0][i], d[1][i - 2] + s[0][i]);
			d[1][i] = max(d[0][i - 1] + s[1][i], d[0][i - 2] + s[1][i]);
			int m = max(d[0][i], d[1][i]);
			Max = max(m, Max);
		}
		cout << Max << '\n';
	}
}