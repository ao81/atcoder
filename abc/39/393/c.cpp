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
	set<pl> a;
	int ans = 0;
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		if (u == v) {
			ans++;
			continue;
		}
		if (u > v) swap(u, v);
		if (a.count({u, v})) {
			ans++;
			continue;
		}
		a.insert({u, v});
	}
	cout << ans << endl;
	return 0;
}