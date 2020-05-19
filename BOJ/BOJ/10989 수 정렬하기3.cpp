#include <iostream>
#include <algorithm>
using namespace std;

int N, num, Max = -1;
int arr[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num]++;
		Max = max(Max, num);
	}
	for (int i = 1; i <= Max; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}