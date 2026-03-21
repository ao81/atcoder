#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, k; cin >> n >> k;
	vl a(n);
	rep(i, 0, n) {
		cin >> a[i];
		a[i] %= k;
	}
	sort(all(a));
	ll ans = a[n - 1] - a[0];
	rep(i, 0, n-1) {
		ll minv = a[i + 1];
		ll maxv = a[i] + k;
		ans = min(ans, maxv - minv);
	}
	cout << ans << endl;
	return 0;
}