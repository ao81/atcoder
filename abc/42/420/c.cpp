#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, q; cin >> n >> q;
	vector<pl> ab(n);
	ll sum = 0;
	rep(i, 0, n) cin >> ab[i].first;
	rep(i, 0, n) cin >> ab[i].second;
	rep(i, 0, n) sum += min(ab[i].first, ab[i].second);
	rep(i, 0, q) {
		char c; cin >> c;
		ll x, v; cin >> x >> v;
		x--;

		sum -= min(ab[x].first, ab[x].second);

		if (c == 'A') ab[x].first = v;
		else ab[x].second = v;

		sum += min(ab[x].first, ab[x].second);
		cout << sum << endl;
	}
	return 0;
}