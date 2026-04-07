#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int x, y; cin >> x >> y;
	int z = y - x, ans = 0;
	while (z > 0) ans++, z -= 10;
	cout << ans << endl;
	return 0;
}