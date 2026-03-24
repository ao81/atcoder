#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int v, a[3];
	cin >> v; rep(i, 0, 3) cin >> a[i];
	int idx = 0;
	while (1) {
		v -= a[idx];
		if (v < 0) break;
		if (++idx > 2) idx = 0;
	}
	char ans[3] = { 'F', 'M', 'T' };
	cout << ans[idx] << endl;
	return 0;
}