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
	vl a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];

	sort(all(a));
	sort(all(b));

	int ans = 0;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (b[j] <= 2 * a[i]) {
			ans++;
			i++;
			j++;
		} else {
			i++;
		}
	}
	
	cout << ans << endl;
	return 0;
}