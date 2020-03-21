#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num;
	int sum = 0;
	int snum;

	for (int i = 0; i < 5; i++)
	{
		cin >> snum;
		sum += pow(snum, 2.0);
	}
	cout << sum % 10 << endl;
}