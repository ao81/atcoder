#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n;
	ll ans = 0;
	cin >> n;
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	int i = 0;
	while (i < n) {
		int j = i;
		while (j < n && a[j] == a[i]) j++;
		ll cnt = j - i;
		if (cnt >= 2) ans += (cnt * (cnt - 1) / 2) * (n - cnt);
		i = j;
	}
	cout << ans << endl;
	return 0;
}