#include <iostream>
using namespace std;

int main()
{
	long int F, i;
	cin >> F >> i;
	long int n = F - 1;
	if (F == 1 || F == 5)
		n += 8 * i;
	else
		n += i / 2 * 8 + i % 2 * (8 - (F - 1) * 2);
	cout << n << endl;
	return 0;
