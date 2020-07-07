#include <iostream>
#include <algorithm>
using namespace std;

struct Obj {
	int data = 0, idx = 0;
};
Obj arr[500001];
int Rank[500001], N, IDT[1 << 20], base;

void update(int a) {
	IDT[a] = 1;
	a >>= 1;
	while (a) {
		IDT[a] = IDT[a * 2] + IDT[a * 2 + 1];
		a >>= 1;
	}
}

int Sum(int a, int b) {
	int sum = 0;
	while (a < b) {
		if (a % 2 == 1) sum += IDT[a], a++;
		if (b % 2 == 0) sum += IDT[b], b--;
		a >>= 1, b >>= 1;
	}
	if (a == b) sum += IDT[a];
	return sum;
}

bool cmp1(Obj a, Obj b) {
	if (a.data < b.data) return true;
	else return false;
}
bool cmp2(Obj a, Obj b) {
	if (a.idx < b.idx) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].data;
		arr[i].idx = i;
		Rank[i] = i;
	}
	for (base = 1; base < N; base *= 2);

	// 속도 데이터를 재설정. (범위가 너무 커서)
	sort(arr + 1, arr + N + 1, cmp1);
	for (int i = 1; i <= N; i++) {
		arr[i].data = i;
	}

	// 다시 idx 순서대로 재정렬.
	sort(arr + 1, arr + N + 1, cmp2);

	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			update(base + arr[i].data - 1);
			continue;
		}
		Rank[i] -= Sum(base, base + arr[i].data - 2);
		update(base + arr[i].data - 1);
	}
	for (int i = 1; i <= N; i++)
		cout << Rank[i] << '\n';
	return 0;
}
