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
	vl a(n), b(n);
	rep(i, 0, n) cin >> a[i] >> b[i];

	int m; cin >> m;
	vector<string> s(m);
	rep(i, 0, m) cin >> s[i];

	set<tuple<int, int, char>> ok;
	for (auto& x : s) {
		int len = x.size();
		rep(i, 0, len) ok.insert({len, i, x[i]});
	}

	rep(i, 0, m) {
		if ((int)s[i].size() != n) {
			cout << "No\n";
			continue;
		}
		bool found = true;
		rep(j, 0, n) {
			char c = s[i][j];
			if (ok.find({a[j], b[j]-1, c}) == ok.end()) {
				found = false;
				break;
			}
		}
		if (found) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}