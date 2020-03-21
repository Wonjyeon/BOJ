#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int R, B;
	int l, w;
	cin >> R >> B;


	for (w = 1; ; w++)
	{
		if (B%w == 0)
		{
			l = B / w;
			if (l * 2 + w * 2 + 4 == R)
			{
				cout << l + 2 << " " << w + 2 << endl;
				break;
			}
		}
	}
	return 0;
}