#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string color[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	string col;
	long long ans;
	int num[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> col;
		for (int j = 0; j < 10; j++)
		{
			if (color[j] == col)
			{
				num[i] = j;
				break;
			}
		}
	}
	ans = num[1] + 10 * num[0];
	ans *= pow(10, num[2]);
	cout << ans << endl;

}