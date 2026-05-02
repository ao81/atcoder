#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

const int MOD = 998244353;

int main(void) {
	string s; cin >> s;
	int len = s.length();
	ll a = 0, b = 0, c = 0, ans = 0;
	for (char ch : s) {
		if (ch == 'a') {
			ll sum = 1 + b + c;
			a = (a + sum) % MOD;
			ans = (ans + sum) % MOD;
		} else if (ch == 'b') {
			ll sum = 1 + a + c;
			b = (b + sum) % MOD;
			ans = (ans + sum) % MOD;
		} else {
			ll sum = 1 + a + b;
			c = (c + sum) % MOD;
			ans = (ans + sum) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}