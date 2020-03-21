#include <iostream>
#include <string>
using namespace std;


int main() {
	int alp[27] = { 0 };
	string word;
	cin >> word;

	for (int i = 0; i < 27; i++) {
		alp[i] = -1;
	}

	for (int i = 0; i < word.length(); i++) {
		if (alp[word[i] - 'a'] == -1 && word[i] >= 'a'&&word[i] <= 'z')
			alp[word[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alp[i] << endl;
	}
}