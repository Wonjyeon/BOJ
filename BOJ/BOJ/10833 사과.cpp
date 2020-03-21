#include <iostream>
using namespace std;

int main()
{
	int num, student, apple;
	cin >> num;

	int app;
	int sum = 0;

	while (num--)
	{
		cin >> student;
		cin >> apple;

		app = apple%student;
		sum += app;
	}
	cout << sum;
}