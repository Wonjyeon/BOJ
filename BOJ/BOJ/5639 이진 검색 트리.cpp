#include <iostream>
using namespace std;

int tree[10001];

void postorder(int start, int end) {
	if (start == end)
		return;
	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}
	int idx = start + 1;
	while (idx < end&&tree[start]>tree[idx])
		idx++;
	postorder(start + 1, idx);
	postorder(idx, end);
	cout << tree[start] << '\n';
}

int main() {
	int i = 0;
	for (i; scanf("%d", tree + i) > 0; i++);
	postorder(0, i);
}