#include <iostream>
using namespace std;

int K = 1, num[13] = { 0 };
int sel[13];

void Print()
{
	for (int i = 0; i < K; i++)
	{
		if (sel[i] == 1)
			cout << num[i] << " ";
	}
	cout << endl;
}

void DFS(int idx, int cnt)
{
	if (cnt == 6)
	{
		Print();
		return;
	}
	for (int i = idx; i < K; i++)
	{
		if (sel[i] == 1)
			continue;
		sel[i] = 1;
		DFS(i, cnt + 1);
		sel[i] = 0;
	}
}


int main()
{
	while (1)
	{
		cin >> K;
		if (K == 0)
			break;
		for (int i = 0; i < K; i++)
		{
			cin >> num[i];
		}
		DFS(0, 0);
		cout << endl;
	}
	return 0;
}