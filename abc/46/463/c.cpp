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
	vector<pl> hl(n);
	rep(i, 0, n) cin >> hl[i].first >> hl[i].second;
	sort(hl.begin(), hl.end(), [](auto& a, auto& b) {
		return a.second < b.second;
		});

	vl mx(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		mx[i] = max(mx[i + 1], hl[i].first);
	}

	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		int idx = upper_bound(hl.begin(), hl.end(), t,
			[](ll val, const pl& elem) {
				return val < elem.second;
			}) - hl.begin();
		cout << mx[idx] << "\n";
	}

	return 0;
}