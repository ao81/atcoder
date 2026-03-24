#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, d; cin >> n >> d;
	vector<string> s(n); rep(i, 0, n) cin >> s[i];
	int mx = 0, ans = 0;
	rep(i, 0, d) {
		bool ok = true;
		rep(j, 0, n) {
			if (s[j][i] == 'x') ok = false;
		}
		if (ok) mx++;
		else {
			ans = max(ans, mx);
			mx = 0;
		}
	}
	cout << max(ans, mx) << endl;
	return 0;
}