#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, M;
	int a = 0;
	char ans[100];
	string post;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> ans[i];

	while (M--)
	{
		cin >> post;
		for (int i = 0; i < post.length(); i++)
		{
			if (a == N)
				break;
			if (post[i] == ans[a])
				a++;
		}
		if (a == N)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		a = 0;
	}
}