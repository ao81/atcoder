#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int t; cin >> t;
	string res;
	while (t--) {
		string s; cin >> s;
		int n = s.size();

		int cnt[26] = {};
		for (char c : s) cnt[c - 'a']++;

		int mxcnt = 0;
		rep(i, 0, 26) if (cnt[i] > mxcnt) mxcnt = cnt[i];

		if (mxcnt > (n + 1) / 2) {
			res += "No\n";
			continue;
		}

		vector<pl> v;
		rep(i, 0, 26) if (cnt[i] > 0) v.push_back({cnt[i], i});
		sort(all(v), greater<pl>());

		string c;
		c.reserve(n);
		for (auto& p : v) c += string(p.first, 'a' + p.second);

		string r(n, ' ');
		int idx = 0;
		for (int i = 0; i < n; i += 2) r[i] = c[idx++];
		for (int i = 1; i < n; i += 2) r[i] = c[idx++];

		res += "Yes\n";
		res += r;
		res += "\n";
	}

	cout << res;
	return 0;
}