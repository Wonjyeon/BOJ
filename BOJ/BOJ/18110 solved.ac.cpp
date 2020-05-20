#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int num[300000];

int main() {
	int N, cnt, avg = 0;
	double sum = 0;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);
	cnt = round(N*0.15);
	for (int i = cnt; i < N - cnt; i++) {
		sum += num[i];
	}
	if (N - 2 * cnt <= 0) cout << 0 << '\n';
	else {
		avg = round(sum / (N - (2 * cnt)));
		cout << avg << '\n';
	}
}