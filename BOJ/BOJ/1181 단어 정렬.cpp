#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 20000;
string str[MAX];

bool cmp(string str1, string str2)
{
	if (str1.size() < str2.size())
		return true;
	else if (str1.size() == str2.size())
	{
		if (str1 < str2)
			return true;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	sort(str, str + N, cmp);
	string temp = str[0];
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && str[i] == temp)
			continue;
		cout << str[i] << "\n";
		temp = str[i];
	}
}