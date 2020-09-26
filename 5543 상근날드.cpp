#include <iostream>
using namespace std;

int main() {
	int MinH = 2001, MinD = 2001, n;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		if (MinH > n) MinH = n;
	}
	for (int i = 0; i < 2; i++) {
		cin >> n;
		if (MinD > n) MinD = n;
	}
	cout << MinH + MinD - 50 << '\n';
	return 0;
}