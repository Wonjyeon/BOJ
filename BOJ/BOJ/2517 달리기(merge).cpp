#include <iostream>
using namespace std;

struct Obj {
	int data = 0, idx = 0;
};

int Rank[500000];
Obj arr[500000], sorted[500000];
int N;


void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left, k = left, j = mid + 1;
	while (i <= mid&&j <= right) {
		if (arr[i].data > arr[j].data)
			sorted[k++] = arr[i++];
		else {
			Rank[arr[j].idx] -= mid + 1 - i;
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
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].data;
		arr[i].idx = i;
		Rank[i] = i;
	}
	merge_sort(1, N);
	for (int i = 1; i <= N; i++) {
		cout << Rank[i] << '\n';
	}
}
