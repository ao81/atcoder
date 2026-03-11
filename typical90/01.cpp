#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, l, k;
	cin >> n >> l >> k;
	vl a(n);
	rep(i, 0, n) cin >> a[i];

	auto check = [&](ll x) {
		ll cut = 0, last = 0;
		rep(i, 0, n) {
			if (a[i] - last >= x) {
				cut++;
				last = a[i];
			}
		}
		if (l - last >= x) cut++;
		return (cut >= k + 1);
	};

	ll left = -1, right = l + 1;
	while (right - left > 1) {
		ll mid = (right + left) / 2;
		if (check(mid)) left = mid;
		else right = mid;
	}

	cout << left << endl;

	return 0;
}