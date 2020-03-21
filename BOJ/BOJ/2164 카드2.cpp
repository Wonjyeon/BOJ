#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> cardSet;

	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cardSet.push(i);
	}



	while (cardSet.size() != 1)
	{
		cardSet.pop();
		cardSet.push(cardSet.front());
		cardSet.pop();
	}
	cout << cardSet.front() << endl;

}