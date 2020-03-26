#include <iostream>
#include <algorithm>
using namespace std;

int N, M, Card[500001], Find[500001];

int Binary_Search(int key) {
	int left = 0, right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == Card[mid])
			return 1;
		if (key < Card[mid]) right = mid - 1;
		else if (key > Card[mid]) left = mid + 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Card[i];
	sort(Card, Card + N);
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> Find[i];
	for (int i = 0; i < M; i++)
		cout << Binary_Search(Find[i]) << ' ';
	cout << '\n';
}