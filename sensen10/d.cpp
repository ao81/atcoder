#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int a, b, c, x, ans = 0;
	cin >> a >> b >> c >> x;
	rep(i, 0, a) {
		rep(j, 0, b) {
			rep(k, 0, c) {
				if (i*500 + j*100 + k*50 == x) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}