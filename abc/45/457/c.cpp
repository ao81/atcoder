#include <iostream>
#include <vector>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, k; cin >> n >> k;
	vvl a(n);
	rep(i, 0, n) {
		int l; cin >> l;
		a[i].resize(l);
		rep(j, 0, l) cin >> a[i][j];
	}
	vl c(n); rep(i, 0, n) cin >> c[i];
	rep(i, 0, n) {
		ll total = c[i] * a[i].size();
		if (k <= total) {
			cout << a[i][(k - 1) % a[i].size()] << endl;
			return 0;
		}
		k -= total;
	}
}