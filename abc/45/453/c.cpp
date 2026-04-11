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
	vl l(n); rep(i, 0, n) cin >> l[i];
	int ans = 0;

	rep(i, 0, (1 << n)) {
		double pos = 0.5;
		int cnt = 0;
		rep(j, 0, n) {
			double mv;
			if ((i >> j) & 1) mv = l[j];
			else mv = -l[j];
			double nx = pos + mv;
			if ((pos < 0) != (nx < 0)) cnt++;
			pos = nx;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}