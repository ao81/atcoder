#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<int>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, p, q, ans;
	cin >> n >> p >> q;
	vl d(n); for(auto& a: d) cin >> a;
	sort(all(d));
	ans = min(p, q + d[0]);
	cout << ans << endl;
	return 0;
}