#include <iostream>
using namespace std;

int main()
{
	int sugar;
	int five;
	int three;
	int count;
	int nsugar;

	cin >> sugar;

	five = sugar / 5;

	if (five == 0)		//5Ű�� ������ ��,
	{
		if (sugar == 3)		//��Ȯ�� 3Ű���̸�,
			cout << "1" << endl;
		else				//�ƴϸ� ������ -1.
			cout << "-1" << endl;
		return 0;
	}
	else				//5Ű�� �̻��� ��,
	{
		while (1)
		{
			nsugar = sugar - five * 5;
			if (nsugar % 3 == 0)
			{
				three = nsugar / 3;
				count = five + three;
				break;
			}
			five--;
			if (five <= 0)
			{
				if (sugar % 3 == 0)
				{
					count = sugar / 3;
				}
				else
				{
					cout << "-1" << endl;
					return 0;
				}

			}
		}
	}
	cout << count << endl;

}