#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 11;
int N, ans = 987654321;
int person[MAX];			// 지역별 인구수
int map[MAX][MAX];
int SELECT[MAX];			// 조합을 위한 배열
int visit[MAX];				// bfs를 위한 배열

							/*	2번 조건 : 선거구에 포함된 구역들끼리 모두 연결되어 있는지?
							-> BFS
							*/
int Check_Connection(vector<int> v, int T) {
	memset(visit, 0, sizeof(visit));
	visit[v[0]] = 1;
	queue<int> q;
	q.push(v[0]);
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			/*	BFS 탐색 조건 3개
			조건 1 : 현재 구역과 탐색하려는 구역이 연결되어 있는지?
			조건 2 : 탐색하려는 구역이 선거구에 맞는 놈인지?
			조건 3 : 아직 방문하지 않은 구역인지?
			*/
			if (map[x][i] && SELECT[i] == T && !visit[i]) {
				visit[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
	// 조건 2에 위배되는지 확인 -> BFS에서 count한 값과 vector의 size가 같다.
	if (v.size() == cnt)
		return 1;
	return 0;

}

int check() {
	/*	선거구가 가질 수 있는 조건들에 대해서 check 해주는 함수.
	조건 1 : 선거구에 포함된 구역의 개수가 1개 이상인지?
	조건 2 : 선거구에 포함된 구역들끼리 모두 연결되어 있는지?
	*/
	vector<int> A, B;
	for (int i = 1; i <= N; i++) {
		if (SELECT[i])
			A.push_back(i);
		else
			B.push_back(i);
	}

	// 1번 조건
	if (A.size() == 0 || B.size() == 0)
		return 0;

	// 2번 조건
	int Astate = Check_Connection(A, 1);
	if (!Astate)
		return 0;
	int Bstate = Check_Connection(B, 0);
	if (!Bstate)
		return 0;
	return 1;
}

void calculate() {
	/*
	인구수 차이를 구하기 위한 함수
	*/
	int A_num = 0, B_num = 0, Diff;
	for (int i = 1; i <= N; i++) {
		if (SELECT[i])
			A_num += person[i];
		else
			B_num += person[i];
	}
	Diff = abs(A_num - B_num);
	if (ans > Diff)
		ans = Diff;
}

void dfs(int idx, int depth) {
	/*
	조합 구현을 위한 DFS 함수
	*/
	if (depth >= 1) {
		if (check())
			calculate();
		// return이 없으니 조심! (1개 이상으로도 계속 구해야 하니까)
	}
	for (int i = idx; i <= N; i++) {
		if (SELECT[i])
			continue;
		SELECT[i] = 1;
		dfs(i, depth + 1);
		SELECT[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> person[i];
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int x; cin >> x;
			map[i][x] = 1;
			map[x][i] = 1;
		}
	}
	// 조합 만들기
	dfs(1, 0);

	if (ans == 987654321)
		cout << -1 << endl;
	else
		cout << ans << endl;
}