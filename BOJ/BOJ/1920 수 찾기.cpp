#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[100001], B[100001];

int Binary_Search(int key) {
	int left = 0, right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == A[mid]) return 1;
		else if (key < A[mid]) right = mid - 1;
		else if (key > A[mid]) left = mid + 1;
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];
	for (int i = 0; i < M; i++) {
		cout << Binary_Search(B[i]) << '\n';
	}
	return 0;
}