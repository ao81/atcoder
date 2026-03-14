#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, ans = 0; cin >> n;
	vl a(n); rep(i, 0, n) cin >> a[i];

	while (true) {
		bool ok = true;
		rep(i, 0, n) {
			if (a[i] % 2 != 0) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
		rep(i, 0, n) a[i] /= 2;
		ans++;
	}
	cout << ans << endl;
	return 0;
}