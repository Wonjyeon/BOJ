#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int in, out;
	int sum = 0;
	int m = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;
		sum += in - out;
		m = max(m, sum);
	}
	cout << m << endl;
}