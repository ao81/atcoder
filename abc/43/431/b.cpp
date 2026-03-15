#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using pl = pair<int, int>;
using vl = vector<int>;
using vvl = vector<vector<int>>;

int main(void) {
	int x, n, q, p, ans;
	cin >> x >> n;
	ans = x;
	vl w(n);
	rep(i, 0, n) cin >> w[i];
	cin >> q;
	vl set(n, 0);
	rep(i, 0, q) {
		cin >> p;
		p--;
		if (set[p] == 0) {
			ans += w[p];
			set[p] = 1;
		} else {
			ans -= w[p];
			set[p] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}