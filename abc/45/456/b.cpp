#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<int>;
using vvl = vector<vector<int>>;

int main(void) {
	vvl a(3, vl(6));
	rep(i, 0, 3) rep(j, 0, 6) cin >> a[i][j];

	double ans = 0.0;
	rep(i, 0, 6) rep(j, 0, 6) rep(k, 0, 6) {
		int s[3] = { a[0][i], a[1][j], a[2][k] };
		sort(s, s + 3);
		if (s[0] == 4 && s[1] == 5 && s[2] == 6) ans += 1.0 / (6*6*6);
	}
	cout << ans << endl;
	return 0;
}