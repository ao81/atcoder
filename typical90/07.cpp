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
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	int q; cin >> q;
	
	rep(i, 0, q) {
		ll b, minn = LONG_LONG_MAX;
		cin >> b;
		auto it = lower_bound(all(a), b);
		if (it != a.end()) minn = min(minn, *it - b);
		if (it != a.begin()) minn = min(minn, b - *prev(it));
		cout << minn << endl;
	}
	return 0;
}