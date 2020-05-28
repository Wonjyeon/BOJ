#include <iostream>
using namespace std;

int arr[9];

int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum -= 100;
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == sum) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << arr[k] << endl;
				}
				return 0;
			}
		}
	}
}