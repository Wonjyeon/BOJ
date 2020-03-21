#include <iostream>
using namespace std;

int main()
{
	int n = 0, i = 0;
	float score[1000];
	float total = 0;
	float max = 0;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> score[i];
		if (score[i] > max)
			max = score[i];
	}
	for (i = 0; i < n; i++)
	{
		score[i] = score[i] / max * 100;
		total += score[i];
	}
	cout << fixed;
	cout.precision(2);
	cout << total / n << endl;

}