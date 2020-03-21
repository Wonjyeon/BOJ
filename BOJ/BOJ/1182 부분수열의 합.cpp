#include <iostream>
using namespace std;

const int MAX = 20;

int N, S;
int arr[MAX];
int ans = 0;

void subset(int index, int sum)
{
	sum += arr[index];
	if (index >= N)
		return;
	if (sum == S)
		ans++;

	subset(index + 1, sum - arr[index]);		// �ش� ���� �� ���� ��
	subset(index + 1, sum);						// �ش� ���� ���� ��
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	subset(0, 0);

	cout << ans << endl;

	return 0;
}