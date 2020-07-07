#include <iostream>
using namespace std;

int main()
{
	int N, max, min, n;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (i == 0)
		{
			min = n;
			max = n;
			continue;
		}
		if (n > max)
			max = n;
		else if (n < min)
			min = n;
	}
	cout << min << " " << max << endl;
	return 0;
}