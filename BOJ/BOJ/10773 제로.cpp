#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	int K, num;
	int ans = 0;
	cin >> K;
	while (K--)
	{
		cin >> num;
		if (num == 0)
			st.pop();
		else
			st.push(num);
	}
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	cout << ans << endl;
	return 0;
}