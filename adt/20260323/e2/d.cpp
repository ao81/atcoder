#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll x, ans; cin >> x;
	if (x >= 0) ans = (x + 9) / 10;
	else ans = x / 10;
	cout << ans << endl;
	return 0;
}