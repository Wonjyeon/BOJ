#include <iostream>
using namespace std;

int main()
{
	int num, i, j, k;
	cin >> num;

	for (i = num; i >= 1; i--)
	{
		for (k = 1; k <= num - i; k++)
			cout << " ";
		for (j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}
	return 0;
}