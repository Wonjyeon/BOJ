#include <iostream>
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	if (n1 > n2)
		cout << '>' << endl;
	else if (n2 > n1)
		cout << '<' << endl;
	else
		cout << "==" << endl;
	return 0;
}