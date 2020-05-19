#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 0, num[1001];
bool check[1001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	check[1] = true;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	int Max = num[N - 1];
	for (int i = 2; i <= Max; i++) {
		if (!check[i]) {
			if (i > 32) continue;
			int tmp = i*i;
			for (tmp; tmp <= Max; tmp += i) {
				check[tmp] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int n = num[i];
		if (!check[n]) ans++;
	}
	cout << ans << '\n';
}