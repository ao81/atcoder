#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, k, res = 0;
	cin >> n >> k;
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	ll sum = 0;

	rep(i, 0, k) sum += a[i];
	if (sum <= 0) res++;

	rep(i, k, n) {
		sum += a[i];
		sum -= a[i - k];
		if (sum <= 0) res++;
	}

	cout << res << endl;
	return 0;
}