#include <iostream>
using namespace std;

typedef long long ll;
int arr[500000], sorted[500000];
ll ans = 0;

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left, k = left, j = mid + 1;
	while (i <= mid&&j <= right) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else {
			ans += (mid + 1) - i;
			sorted[k++] = arr[j++];
		}
	}
	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}
	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	merge_sort(0, N - 1);
	cout << ans << '\n';
	return 0;
}