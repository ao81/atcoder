#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, l, r; ll ans = 0;
	string s;
	cin >> n >> l >> r >> s;
	rep(c, 0, 26) {
		vl a(n + 1, 0);
		rep(i, 0, n) a[i+1] = a[i] + (s[i] - 'a' == c ? 1 : 0);
		rep(i, 0, n) {
			if (s[i] - 'a' != c) continue;
			int lo = i - r, hi = i - l;
			if (hi < 0) continue;
			lo = max(0, lo);
			ans += a[hi + 1] - a[lo];
		}
	}
	cout << ans << endl;
	return 0;
}