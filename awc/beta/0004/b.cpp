#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, t, res = 0;
	cin >> n >> t;
	rep(i, 0, n) {
		ll a, b;
		cin >> a >> b;
		res += max(a - b * t, (ll)0);
	}
	cout << res << endl;
	return 0;
}