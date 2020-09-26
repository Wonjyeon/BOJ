#include <iostream>
using namespace std;

int main() {
	int N, T, C, P, ans = 0, day = 0, cnt = 1;
	cin >> N >> T >> C >> P;
	while (cnt <= N) {
		cnt += T;
		day++;
	}
	ans = (day - 1)*C*P;
	cout << ans << '\n';
	return 0;
}