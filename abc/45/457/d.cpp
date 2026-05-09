#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int n; ll k;
vl a;

bool check(ll x) {
	ll need = 0;
	rep(i, 0, n) {
		if (a[i] < x) need += (x - a[i] + i) / (i + 1);
		if (need > k) return false;
	}
	return true;
}

int main(void) {
	cin >> n >> k;
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	
	ll lo = 0, hi = 2e18;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (check(mid)) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << endl;
	return 0;
}