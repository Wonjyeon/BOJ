#include <iostream>
using namespace std;

int main()
{
	int num, i, j;
	cin >> num;
	for (i = num; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}


}