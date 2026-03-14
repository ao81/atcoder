#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (ll i = (l); i <= (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll cntEven(ll l, ll r) {
	if (l > r) return 0;
	auto d = [](ll n) -> ll {
		return (n >= 0) ? n / 2 : (n - 1) / 2;
	};
	return d(r) - d(l - 1);
}

int main(void) {
	ll l, r, d, u;
	cin >> l >> r >> d >> u;
	ll ans = 0;
	rep(x, l, r) {
		ll ax = abs(x);
		if (ax % 2 == 0) {
			ll yl = max(-ax, d), yr = min(ax, u);
			if (yl <= yr) ans += yr - yl + 1;
		}
		ans += cntEven(d, min(-ax - 1, u));
		ans += cntEven(max(ax + 1, d), u);
	}
	cout << ans << endl;
	return 0;
}