#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	int cnt = 0;
	int grade;
	float avg = 0;
	float total = 0;
	int std = 0;
	float score[1000];

	cin >> N;
	while (N--)
	{
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			cin >> score[i];
			total += score[i];
		}
		avg = total / cnt;
		for (int i = 0; i < cnt; i++)
		{
			if (score[i] > avg)
				std++;
		}
		cout << fixed;
		cout.precision(3);
		cout << (double)std / cnt * 100 << "%" << endl;
		total = 0;
		avg = 0;
		std = 0;
	}
}