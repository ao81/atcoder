#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	map<string, int> t;
	rep(i, 0, n - k + 1) {
		t[s.substr(i, k)]++;
	}
	int maxcnt = 0;
	for (auto [str, cnt]: t) maxcnt = max(maxcnt, cnt);
	cout << maxcnt << endl;
	for (auto [str, cnt]: t) if (cnt == maxcnt) cout << str << " ";
	cout << endl;
	return 0;
}