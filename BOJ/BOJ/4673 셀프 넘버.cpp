#include <iostream>
using namespace std;

int dn(int n)		// n으로 만들어지는 숫자 => 셀프 넘버가 아닌 숫자를 생성.
{
	int result = n;
	while (n != 0)		// n이 0보다 클 때까지.
	{
		result += n % 10;		// n의 1의 자리부터 더함.
		n = n / 10;				// n의 자릿수를 줄임.
	}
	return result;		// 셀프 넘버가 아닌 수를 반환.
}

int main()
{
	int arr[10001];
	arr[0] = 1;
	int n = 0;		// 셀프 넘버를 만들 생성자.

					//배열에 1~9999까지 수를 채워줌.
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
				if (n <= 10000)		// 셀프넘버가 10000보다 작으면 (12이면)
					arr[n - 1] = 0;			// 해당 자리의 수를 0으로. (11번에 12가 들어있음)
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