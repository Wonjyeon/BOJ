#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dx = x1 - x2;
		int dy = y1 - y2;
		long long d = dx*dx + dy*dy;

		if (r1 > r2) swap(r1, r2);
		long long add = r1 + r2;
		add *= add;
		long long sub = r2 - r1;
		sub *= sub;

		if (d > sub && d < add)
			cout << "2\n";
		else if (d == add || (d == sub && d != 0))
			cout << "1\n";
		else if (d > add || d < sub)
			cout << "0\n";
		else if (d == 0) {
			if (r1 == r2) cout << "-1\n";
			else cout << "0\n";
		}
	}
	return 0;
}