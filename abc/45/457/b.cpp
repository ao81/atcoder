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
	vvl a(n);
	rep(i, 0, n) {
		int l; cin >> l;
		a[i].resize(l);
		rep(j, 0, l) cin >> a[i][j];
	}
	int x, y; cin >> x >> y;
	cout << a[x - 1][y - 1] << "\n";
	return 0;
}