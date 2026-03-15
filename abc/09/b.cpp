#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, x, ans = 0;
	cin >> n >> x;
	vl m(n); for (auto& a: m) cin >> a;
	rep(i, 0, n) {
		x -= m[i];
		ans++;
	}
	sort(all(m));
	while (1) {
		if (x - m[0] < 0) break;
		x -= m[0];
		ans++;
	}
	cout << ans << endl;
	return 0;
}