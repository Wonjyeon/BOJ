#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int T, N, M, ipt, count = 0;
	cin >> T;

	while (T--)
	{
		count = 0;
		queue<pair<int, int>> print;
		priority_queue<int> pq;

		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> ipt;
			print.push({ i,ipt });
			pq.push(ipt);
		}
		while (!print.empty())
		{
			int index = print.front().first;
			int value = print.front().second;
			print.pop();

			if (value == pq.top())
			{
				pq.pop();
				count++;
				if (index == M)
				{
					cout << count << endl;
					break;
				}
			}
			else
				print.push({ index,value });
		}
	}
}