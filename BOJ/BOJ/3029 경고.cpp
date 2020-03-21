#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	//1 : 현재 시각. 2 : 던질 시각. => 2-1을 해야함.
	int h1, h2, m1, m2, s1, s2;
	char c;
	cin >> h1 >> c >> m1 >> c >> s1;
	cin >> h2 >> c >> m2 >> c >> s2;

	if (s1 > s2)
	{
		s2 += 60;
		m2 -= 1;
	}
	if (m1 > m2)
	{
		m2 += 60;
		h2 -= 1;
	}
	if (h1 > h2)
	{
		h2 += 24;
	}
	int ans[3];
	ans[0] = h2 - h1;
	ans[1] = m2 - m1;
	ans[2] = s2 - s1;

	if (!ans[0] && !ans[1] && !ans[2]) {
		cout << "24:00:00" << endl;
		return 0;
	}


	for (int i = 0; i < 3; i++)
	{
		if (ans[i] < 10)
			cout << 0;
		cout << ans[i];
		if (i == 2)
			break;
		else
			cout << ":";
	}


	return 0;
}