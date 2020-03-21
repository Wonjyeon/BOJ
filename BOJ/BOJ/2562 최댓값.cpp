#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[9];
	int max, ans;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (i == 0)
		{
			max = arr[i];
			ans = i + 1;
		}
		else if (arr[i] > max)
		{
			max = arr[i];
			ans = i + 1;
		}
	}
	cout << max << endl << ans << endl;
}