#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, m; cin >> n >> m;
	map<pl, int> a;
	int ans = 0;
	rep(i, 0, m) {
		ll r, c; cin >> r >> c;
		r--, c--;
		if (a[{r,c}] == 0 && a[{r+1,c}] == 0 && a[{r,c+1}] == 0 && a[{r+1,c+1}] == 0) {
			a[{r,c}] = a[{r+1,c}] = a[{r,c+1}] = a[{r+1,c+1}] = 1;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}