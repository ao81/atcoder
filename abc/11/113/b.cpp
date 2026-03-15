#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, t, a;
	cin >> n >> t >> a;
	pair<double, int> ans = {DBL_MAX, 0};
	rep(i, 0, n) {
		int h; cin >> h;
		ans = min(ans, {abs((t - h * 0.006) - a), i + 1});
	}
	cout << ans.second << endl;
	return 0;
}