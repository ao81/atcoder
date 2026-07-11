#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m; cin >> n >> m;
	vl r(m), c(m);
	rep(i, 0, m) cin >> r[i] >> c[i];
	ll ans = 0;
	vector<bool> rr(n, false), cc(n, false);
	for (int i = m - 1; i >= 0; i--) {
		if (!rr[r[i]] && !cc[c[i]]) ans++;
		rr[r[i]] = cc[c[i]] = true;
	}
	cout << ans << "\n";
	return 0;
}