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
		int n;
		string s;
		cin >> n >> s;
		vl x(n), y(n - 1);
		rep(i, 0, n) cin >> x[i];
		rep(i, 0, n - 1) cin >> y[i];

		// 0:R 1:S
		vvl dp(n, vl(2));

		auto cost = [&](int i, int c) -> ll {
			int cur = (s[i] == 'S') ? 1 : 0;
			return (cur == c) ? 0 : -x[i];
			};

		dp[0][0] = cost(0, 0);
		dp[0][1] = cost(0, 1);

		rep(i, 1, n) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + cost(i, 0);
			dp[i][1] = max(dp[i - 1][0] + y[i - 1], dp[i - 1][1]) + cost(i, 1);
		}

		cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
	}

	return 0;
}