#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<pair<int, int>> v;
	int N;
	cin >> N;

	int *B = new int[N];

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		B[v[i].second] = i;
	}
	for (int i = 0; i<N; i++)
	{
		cout << B[i] << " ";
	}
	cout << "\n";
	return 0;

}