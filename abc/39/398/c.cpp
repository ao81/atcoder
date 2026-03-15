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
	map<ll, vector<int>> a;
	rep(i, 0, n) {
		ll x; cin >> x;
		a[x].push_back(i + 1);
	}
	ll ans = -1;
	int idx = -1;
	for (auto [x, y]: a) {
		if (y.size() == 1 && x > ans) {
			ans = x;
			idx = y[0];
		}
	}
	cout << idx << endl;
	return 0;
}