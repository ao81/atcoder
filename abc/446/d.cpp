#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<int>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, ans = 0;
	cin >> n;
	map<int, int> dp;
	rep(i, 0, n) {
		int a;
		cin >> a;
		dp[a] = dp[a - 1] + 1;
		if (dp[a] > ans) ans = dp[a];
	}
	cout << ans << endl;
	return 0;
}	