#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, B, C;
	long long sum = 0;
	vector<int> v;
	cin >> N;
	v.resize(N);
	sum += N;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	cin >> B >> C;
	for (int i = 0; i < v.size(); i++)
	{
		int num = v[i] - B;
		if (num <= 0)
			continue;
		if (num%C == 0)
			sum += num / C;
		else
			sum += (num / C) + 1;
	}
	cout << sum << endl;
	return 0;
}