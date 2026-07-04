#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	string s; cin >> s;

	deque<int> dq;
	bool rev = false;

	rep(i, 1, n + 1) {
		if (!rev) dq.push_back(i);
		else dq.push_front(i);
		if (s[i - 1] == 'o') rev = !rev;
	}

	if (rev) {
		for (auto it = dq.rbegin(); it != dq.rend(); it++) {
			cout << *it << " ";
		}
	} else {
		for (auto it = dq.begin(); it != dq.end(); it++) {
			cout << *it << " ";
		}
	}
	cout << "\n";

	return 0;
}