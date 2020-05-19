#include <iostream>
#include <algorithm>
using namespace std;

int fibo[40][2];

int main() {
	int T, N;
	fibo[0][0] = 1, fibo[0][1] = 0;
	fibo[1][0] = 0, fibo[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}
	cin >> T;
	while (T--) {
		cin >> N;
		cout << fibo[N][0] << ' ' << fibo[N][1] << '\n';
	}
}