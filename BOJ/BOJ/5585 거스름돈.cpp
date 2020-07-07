#include <iostream>
using namespace std;

int main()
{
	int money;
	scanf("%d", &money);
	int cash = 0;
	int n = 1000 - money;

	while (n > 0)
	{
		if (n >= 500)
		{
			n = n - 500;
			cash++;
			continue;
		}
		if (n >= 100)
		{
			n = n - 100;
			cash++;
			continue;
		}
		if (n >= 50)
		{
			n = n - 50;
			cash++;
			continue;
		}
		if (n >= 10)
		{
			n = n - 10;
			cash++;
			continue;
		}
		if (n >= 5)
		{
			n = n - 5;
			cash++;
			continue;
		}
		if (n >= 1)
		{
			n = n - 1;
			cash++;
			continue;
		}
		if (n == 0)
			break;
	}
	printf("%d\n", cash);
	return 0;
}