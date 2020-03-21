#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str1 = "ABC";
	string str2 = "BABC";
	string str3 = "CCAABB";

	int N, t = 0, p = 0, q = 0, max = -1;;
	int cnt[3] = { 0,0,0 };
	char Ans[100];


	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> Ans[i];
		if (t == str1.length())
			t = 0;
		if (str1[t] == Ans[i]) {
			cnt[0]++;
		}
		if (p == str2.length())
			p = 0;
		if (str2[p] == Ans[i])
			cnt[1]++;
		if (q == str3.length())
			q = 0;
		if (str3[q] == Ans[i])
			cnt[2]++;
		t++;
		p++;
		q++;
	}

	for (int i = 0; i < 3; i++)
	{
		if (cnt[i] > max)
			max = cnt[i];
	}
	cout << max << endl;

	for (int i = 0; i < 3; i++)
	{
		if (cnt[i] == max)
		{
			switch (i)
			{
			case 0:
				cout << "Adrian" << endl;
				break;
			case 1:
				cout << "Bruno" << endl;
				break;
			case 2:
				cout << "Goran" << endl;
				break;
			}
		}
	}

}