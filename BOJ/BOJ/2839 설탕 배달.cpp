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

	if (five == 0)		//5키로 이하일 때,
	{
		if (sugar == 3)		//정확히 3키로이면,
			cout << "1" << endl;
		else				//아니면 무조건 -1.
			cout << "-1" << endl;
		return 0;
	}
	else				//5키로 이상일 때,
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