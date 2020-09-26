#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int arr[15] = { 1 };

	while (1)
	{
		int idx = 0;
		int count = 0;
		int num = 100;
		while (1)
		{
			cin >> num;
			if (num == -1)
				return 0;
			if (num == 0)
				break;
			arr[idx] = num;
			idx++;
		}

		for (int i = 0; i < idx; i++)
		{
			for (int j = 0; j < idx; j++)
			{
				if (arr[j] == 2 * arr[i])
					count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}