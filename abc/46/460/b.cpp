#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int t; cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		ll dx = x1 - x2;
		ll dy = y1 - y2;
		ll d2 = dx * dx + dy * dy;

		ll rsum = r1 + r2;
		ll rdiff = r1 - r2;

		ll rsum2 = rsum * rsum;
		ll rdiff2 = rdiff * rdiff;

		if (rdiff2 <= d2 && d2 <= rsum2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
