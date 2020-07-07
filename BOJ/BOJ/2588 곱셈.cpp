#include <iostream>
using namespace std;

int main() {
	int N1, N2;
	cin >> N1 >> N2;

	cout << N1*(N2 % 10) << endl;
	cout << N1*((N2 / 10) % 10) << endl;
	cout << N1*(N2 / 100) << endl;
	cout << N1*N2 << endl;
	return 0;
}