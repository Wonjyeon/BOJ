#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 11;
int N, ans = 987654321;
int person[MAX];			// ������ �α���
int map[MAX][MAX];
int SELECT[MAX];			// ������ ���� �迭
int visit[MAX];				// bfs�� ���� �迭

							/*	2�� ���� : ���ű��� ���Ե� �����鳢�� ��� ����Ǿ� �ִ���?
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
			/*	BFS Ž�� ���� 3��
			���� 1 : ���� ������ Ž���Ϸ��� ������ ����Ǿ� �ִ���?
			���� 2 : Ž���Ϸ��� ������ ���ű��� �´� ������?
			���� 3 : ���� �湮���� ���� ��������?
			*/
			if (map[x][i] && SELECT[i] == T && !visit[i]) {
				visit[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
	// ���� 2�� ����Ǵ��� Ȯ�� -> BFS���� count�� ���� vector�� size�� ����.
	if (v.size() == cnt)
		return 1;
	return 0;

}

int check() {
	/*	���ű��� ���� �� �ִ� ���ǵ鿡 ���ؼ� check ���ִ� �Լ�.
	���� 1 : ���ű��� ���Ե� ������ ������ 1�� �̻�����?
	���� 2 : ���ű��� ���Ե� �����鳢�� ��� ����Ǿ� �ִ���?
	*/
	vector<int> A, B;
	for (int i = 1; i <= N; i++) {
		if (SELECT[i])
			A.push_back(i);
		else
			B.push_back(i);
	}

	// 1�� ����
	if (A.size() == 0 || B.size() == 0)
		return 0;

	// 2�� ����
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
	�α��� ���̸� ���ϱ� ���� �Լ�
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
	���� ������ ���� DFS �Լ�
	*/
	if (depth >= 1) {
		if (check())
			calculate();
		// return�� ������ ����! (1�� �̻����ε� ��� ���ؾ� �ϴϱ�)
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
	// ���� �����
	dfs(1, 0);

	if (ans == 987654321)
		cout << -1 << endl;
	else
		cout << ans << endl;
}