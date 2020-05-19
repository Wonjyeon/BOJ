#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
	int st, et;
};
int N;
vector<meeting> v;

bool cmp(meeting A, meeting B) {
	if (A.et == B.et)
		return A.st < B.st;
	else return A.et < B.et;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0, now_time = 0;
	for (int i = 0; i < N; i++) {
		if (now_time <= v[i].st) {
			now_time = v[i].et;
			ans++;
		}
	}
	cout << ans << '\n';
}