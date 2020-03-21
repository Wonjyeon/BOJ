#include <iostream>
using namespace std;

int main()
{
	int num, cnt, x, y, sum;
	cnt = 0; sum = 0; x = 1, y = 1;

	cin >> num;

	for (int i = 1; i < num; i++) {
		num -= i;
		cnt++;
	}
	sum = cnt + 2;
	if (sum % 2 == 0) {
		while (num > 0) {
			x = sum - y;
			y++;
			num--;
		}
		y--;
	}
	else {
		while (num > 0) {
			y = sum - x;
			x++;
			num--;
		}
		x--;
	}

	cout << x << "/" << y << endl;



}