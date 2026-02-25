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
	rep(i, 0, m) {
		int m;
		cin >> m;
		ans += a[m - 1];
	}
	cout << ans << endl;
	return 0;
}