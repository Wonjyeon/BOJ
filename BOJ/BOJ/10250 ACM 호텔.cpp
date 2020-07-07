#include <iostream>
using namespace std;

int main() {
	int testCase, height, width, num;
	cin >> testCase;

	int x, y;
	while (testCase > 0) {
		testCase--;
		cin >> height >> width >> num;

		if (num % height == 0)
		{
			x = num / height;
			y = height;
		}
		else
		{
			x = (num / height) + 1;
			y = num % height;
		}
		if (x < 10)
		{
			cout << y << "0" << x << endl;
		}
		else
		{
			cout << y << x << endl;
		}
	}
	return 0;
}