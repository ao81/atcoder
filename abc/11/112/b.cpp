#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int N, T, ans = INT_MAX;
	cin >> N >> T;
	vector<pair<int, int>> r(N);
	for (auto& [c, t] : r) cin >> c >> t;
	for (auto& [c, t] : r) if (t <= T) ans = min(c, ans);
	if (ans == INT_MAX) cout << "TLE" << endl;
	else cout << ans << endl;
	return 0;
}