#include <iostream>
using namespace std;

int main() {
	int day = 0;
	int night = 0;
	int height = 0;
	int cnt = 0;

	scanf("%d %d %d", &day, &night, &height);

	int n = height - day;
	if (n % (day - night) == 0)
	{
		cnt = n / (day - night) + 1;
	}
	else
	{
		cnt = n / (day - night) + 2;
	}
	printf("%d\n", cnt);
}