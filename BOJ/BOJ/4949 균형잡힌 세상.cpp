#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	while (1) {
		char str[101];
		cin.getline(str, 101);
		stack<char> s;
		if (!strcmp(str, ".")) break;
		int flag = 0;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					flag = 1;
					break;
				}
				s.pop();
			}
			else if (str[i] == ']') {
				if (s.empty() || s.top() != '[') {
					flag = 1;
					break;
				}
				s.pop();
			}
		}
		if (flag || !s.empty()) cout << "no" << endl;
		else cout << "yes" << endl;
	}

	return 0;
}