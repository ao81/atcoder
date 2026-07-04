#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int x, y, l, r, a, b;
	cin >> x >> y >> l >> r >> a >> b;
	int ans = 0;
	rep(i, a, b) {
		if (l <= i && i < r) ans += x;
		else ans += y;
	}
	cout << ans << "\n";
	return 0;
}