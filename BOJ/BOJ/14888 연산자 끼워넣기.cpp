#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, MAX = -INF, MIN = INF;
int num[11], op[4];

void dfs(int plus, int minus, int multiply, int divide, int cnt, int sum) {
	if (cnt == N) {
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
		return;
	}
	if (plus > 0)
		dfs(plus - 1, minus, multiply, divide, cnt + 1, sum + num[cnt]);
	if (minus > 0)
		dfs(plus, minus - 1, multiply, divide, cnt + 1, sum - num[cnt]);
	if (multiply > 0)
		dfs(plus, minus, multiply - 1, divide, cnt + 1, sum * num[cnt]);
	if (divide > 0)
		dfs(plus, minus, multiply, divide - 1, cnt + 1, sum / num[cnt]);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
	dfs(op[0], op[1], op[2], op[3], 1, num[0]);
	printf("%d\n%d\n", MAX, MIN);
}