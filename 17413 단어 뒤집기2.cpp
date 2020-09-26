#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str, ans = "";
	stack<char> s;
	getline(cin, str);
	int len = str.size();
	int idx = 0;
	while (idx < len) {
		if (str[idx] == '<') {
			ans += str[idx];
			idx++;
			while (str[idx] != '>') {
				ans += str[idx];
				idx++;
			}
			ans += str[idx];
			idx++;
		}
		else if (str[idx] == ' ') {
			ans += str[idx];
			idx++;
		}
		else {
			while (str[idx] != '<' && str[idx] != ' ' && str[idx] != '\0') {
				s.push(str[idx]);
				idx++;
			}
			while (!s.empty()) {
				ans += s.top();
				s.pop();
			}
		}
	}
	cout << ans << endl;
	return 0;
}