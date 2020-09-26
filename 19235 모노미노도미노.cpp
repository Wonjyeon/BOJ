#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, t, x, y, grade = 0;
int blockArr[2][6][4];

void checkSpecial() {
	for (int c = 0; c < 2; c++) {
		bool zeroFlag = false;
		bool oneFlag = false;
		for (int j = 0; j < 4; j++) {
			if (blockArr[c][0][j] != 0) {
				zeroFlag = true;
				break;
			}
		}
		if (zeroFlag == true) {
			for (int i = 5; i >= 4; i--) {
				for (int j = 0; j < 4; j++) {
					blockArr[c][i][j] = 0;
				}
			}
			for (int i = 3; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					blockArr[c][i + 2][j] = blockArr[c][i][j];
					blockArr[c][i][j] = 0;
				}
			}
			continue;
		}
		for (int j = 0; j < 4; j++) {
			if (blockArr[c][1][j] != 0) {
				oneFlag = true;
				break;
			}
		}
		if (oneFlag == true) {
			for (int j = 0; j < 4; j++) {
				blockArr[c][5][j] = 0;
			}

			for (int i = 4; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					blockArr[c][i + 1][j] = blockArr[c][i][j];
					blockArr[c][i][j] = 0;
				}
			}
		}
	}
}

void moveBlock(int c) {
	bool stopFlag = false;
	while (!stopFlag) {
		int cnt = 0;		// 이동한 블록 수
		for (int i = 4; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				int type = blockArr[c][i][j];
				if (type == 0) continue;
				if (type == 2) {
					if (blockArr[c][i + 1][j] == 0 && blockArr[c][i + 1][j + 1] == 0) {
						blockArr[c][i + 1][j] = type;
						blockArr[c][i + 1][j + 1] = blockArr[c][i][j + 1];
						blockArr[c][i][j] = 0;
						blockArr[c][i][j + 1] = 0;
						cnt++;
					}
					j++;
				}
				else {
					if (blockArr[c][i + 1][j] == 0) {
						blockArr[c][i][j] = 0;
						blockArr[c][i + 1][j] = type;
						cnt++;
					}
				}
			}
		}
		if (cnt == 0)		// 하나도 이동하지 않았다면
			stopFlag = true;
	}
}

void updateGrade() {
	for (int c = 0; c < 2; c++) {
		while (1) {
			int sum = 0;			// 삭제된 행 or 열의 수
			for (int i = 5; i >= 0; i--) {
				int cnt = 0;
				for (int j = 0; j < 4; j++) {
					if (blockArr[c][i][j] == 0) break;
					cnt++;
				}
				if (cnt == 4) {
					sum++;
					for (int j = 0; j < 4; j++) 
						blockArr[c][i][j] = 0;
					grade++;
				}
			}
			if (sum == 0) break;
			else moveBlock(c);
		}

	}
	checkSpecial();
}

void insert() {
	for (int c = 0; c < 2; c++) {
		int tempX = 0;
		if (c == 1) {
			swap(x, y);
			if (t == 2) t = 3;
			else if (t == 3) t = 2;
		}

		if (t == 1) {
			while (tempX < 6 && blockArr[c][tempX][y] == 0)
				tempX++;
			blockArr[c][tempX - 1][y] = t;
		}
		else if (t == 2) {
			while (tempX < 6 && blockArr[c][tempX][y] == 0 && blockArr[c][tempX][y + 1] == 0)
				tempX++;
			blockArr[c][tempX - 1][y] = t;
			blockArr[c][tempX - 1][y + 1] = t;
		}
		else if (t == 3) {
			while (tempX < 6 && blockArr[c][tempX][y] == 0)
				tempX++;
			blockArr[c][tempX - 1][y] = t;
			blockArr[c][tempX - 2][y] = t;
		}
	}
	updateGrade();
}

int blockCount() {
	int cnt = 0;
	for (int c = 0; c < 2; c++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (blockArr[c][i][j] != 0)
					cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);  cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t >> x >> y;
		insert();
	}
	cout << grade << endl;
	cout << blockCount() << endl;
}
