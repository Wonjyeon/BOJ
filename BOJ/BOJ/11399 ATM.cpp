#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int tmp = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		tmp += arr[i];
		sum += tmp;
	}
	cout << sum << endl;

	return 0;
}