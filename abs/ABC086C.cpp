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
	int lt = 0, lx = 0, ly = 0;
	bool ok = true;
	rep(i, 0, n) {
		int t, x, y; cin >> t >> x >> y;
		int d = abs(lx - x) + abs(ly - y);
		if (d > t - lt || (t - lt - d) % 2 != 0) {
			ok = false;
			break;
		}
		lt = t, lx = x, ly = y;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}