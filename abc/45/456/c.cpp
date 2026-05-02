#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s; cin >> s;
	int len = s.length();
	ll ans = 0;
	ll rp = 1;
	rep(i, 0, len) {
		if (i > 0 && s[i] != s[i - 1]) rp++;
		else if (i > 0) rp = 1;
		ans += rp;
	}
	cout << ans % 998244353 << endl;
}