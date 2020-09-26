#include <iostream>
using namespace std;

int dn(int n)		// n���� ��������� ���� => ���� �ѹ��� �ƴ� ���ڸ� ����.
{
	int result = n;
	while (n != 0)		// n�� 0���� Ŭ ������.
	{
		result += n % 10;		// n�� 1�� �ڸ����� ����.
		n = n / 10;				// n�� �ڸ����� ����.
	}
	return result;		// ���� �ѹ��� �ƴ� ���� ��ȯ.
}

int main()
{
	int arr[10001];
	arr[0] = 1;
	int n = 0;		// ���� �ѹ��� ���� ������.

					//�迭�� 1~9999���� ���� ä����.
	for (int i = 1; i < 10000; i++)
	{
		arr[i] = arr[i - 1] + 1;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] != 0)
		{
			n = i + 1;
			while (n <= 10000)
			{
				n = dn(n);
				if (n <= 10000)		// �����ѹ��� 10000���� ������ (12�̸�)
					arr[n - 1] = 0;			// �ش� �ڸ��� ���� 0����. (11���� 12�� �������)
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << endl;
	}
	return 0;
}