#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m;
	cin >> n >> m;
	vl c(m);
	rep(i, 0, m) cin >> c[i];
	
	vl need(m, 0);
	rep(i, 0, n) {
		ll a, b;
		cin >> a >> b;
		need[a - 1] += b;
	}

	ll total = 0;
	rep(i, 0, m) {
		total += min(c[i], need[i]);
	}
	cout << total << endl;
	return 0;
}