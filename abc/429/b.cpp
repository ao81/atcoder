#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m, ans = 0;
	cin >> n >> m;
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) {
		int x = 0;
		if (i != 0) {
			rep(j, 0, i) x += a[j];
		}
		if (i != n - 1) {
			rep(j, i+1, n) x += a[j];
		}
		if (x == m) {
			ans = 1;
			break;
		}
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}