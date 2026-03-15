#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, ans = INT_MAX; cin >> n;
	vector<int> a(n); for (auto& x: a) cin >> x;
	map<int, int> last;
	rep(i, 0, n) {
		if (last.count(a[i])) {
			ans = min(ans,  i - last[a[i]] + 1);
		}
		last[a[i]] = i;
	}
	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}