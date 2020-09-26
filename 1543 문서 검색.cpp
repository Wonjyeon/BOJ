#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S, subS;
	getline(cin, S);
	getline(cin, subS);

	if (subS.length() > S.length())
		cout << 0 << "\n";

	else {
		int result = 0;

		for (int i = 0; i < S.length() - subS.length() + 1; i++) {
			bool same = true;

			for (int j = 0; j < subS.length(); j++) {
				if (S[i + j] != subS[j]) {
					same = false;
					break;
				}
			}
			if (same) {
				result++;
				i += subS.size() - 1;
			}
		}
		cout << result << "\n";
	}
	return 0;
}