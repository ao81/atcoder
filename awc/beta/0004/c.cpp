#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, minh = 0, maxh = 0;
	cin >> n;
	rep(i, 0, n) {
		ll h;
		cin >> h;
		minh = min(minh, h);
		maxh = max(maxh, h);
	}
	cout << abs((minh - maxh) * 2) << endl;
	return 0;
}