#include <iostream>
using namespace std;

int main()
{
	int num, i;
	cin >> num;
	for (i = 1; i <= 9; i++)
		cout << num << " * " << i << " = " << num*i << endl;
	return 0;
}