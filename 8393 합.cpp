#include <iostream>
using namespace std;

int main()
{
	int i, num;
	int cnt = 0;
	cin >> num;
	for (i = 1; i <= num; i++)
		cnt += i;
	cout << cnt << endl;
	return 0;
}