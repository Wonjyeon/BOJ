#include <iostream>
using namespace std;

char tree[27][3];
int N;

void preorder(int root) {
	cout << tree[root][0];
	if (tree[root][1] != '.')
		preorder(tree[root][1] - '0' - 17);
	if (tree[root][2] != '.')
		preorder(tree[root][2] - '0' - 17);
}
void inorder(int root) {
	if (tree[root][1] != '.')
		inorder(tree[root][1] - '0' - 17);
	cout << tree[root][0];
	if (tree[root][2] != '.')
		inorder(tree[root][2] - '0' - 17);
}
void postorder(int root) {
	if (tree[root][1] != '.')
		postorder(tree[root][1] - '0' - 17);
	if (tree[root][2] != '.')
		postorder(tree[root][2] - '0' - 17);
	cout << tree[root][0];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char v, l, r;
		cin >> v >> l >> r;
		int idx = v - '0' - 17;
		tree[idx][0] = v;
		tree[idx][1] = l;
		tree[idx][2] = r;
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}