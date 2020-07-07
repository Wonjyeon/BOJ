#include <iostream>
#define MAX 20
#define ABS(x) (x)>0?(x):-(x)
using namespace std;


int arr[MAX][MAX];
int check[MAX];
int N, ans = 987654321;

void dfs(int depth, int pos) {
	if (depth == N / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i] && check[j])
					start += arr[i][j];
				else if (!check[i] && !check[j])
					link += arr[i][j];
			}
		}
		int tmp = ABS(start - link);
		if (tmp < ans)
			ans = tmp;
		return;
	}
	for (int i = pos; i < N - 1; i++) {
		check[i] = 1;
		dfs(depth + 1, i + 1);
		check[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
