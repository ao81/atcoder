#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, ans = 0;
	cin >> n;
	vl p(n);
	for (auto& a: p) cin >> a;
	sort(all(p));
	p[n-1] /= 2;
	for (auto a: p) ans += a;
	cout << ans << endl;
	return 0;
}