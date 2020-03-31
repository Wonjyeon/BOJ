#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int table[1001][1001];

int main() {
	int LCS_length = 0, MAX = 0;
	string str1, str2;
	cin >> str1 >> str2;
	str1 = "0" + str1, str2 = "0" + str2;
	int len1 = str1.length(), len2 = str2.length();
	for (int i = 0; i < len1; i++)
		table[0][i] = 0;
	for (int i = 1; i < len2; i++) {
		table[i][0] = 0;
		MAX = 0;
		for (int j = 1; j < len1; j++) {
			if (str1[j] == str2[i]) {
				table[i][j] = table[i - 1][j - 1] + 1;
				MAX = table[i][j];
			}
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
		LCS_length = max(LCS_length, MAX);
	}
	cout << LCS_length << '\n';
	if (LCS_length == 0) return 0;

	string LCS = "";
	int tmp1 = LCS_length, tmp2 = tmp1 - 1, j_idx = len1 - 1;
	for (int i = len2 - 1; i > 0; i--) {
		for (int j = j_idx; j > 0; j--) {
			if (table[i][j] == tmp1 && table[i - 1][j] == tmp2 && table[i][j - 1] == tmp2 && table[i - 1][j - 1] == tmp2) {
				tmp1--, tmp2--, j_idx = j;
				LCS = str2[i] + LCS;
				break;
			}
		}
	}
	cout << LCS << '\n';
}