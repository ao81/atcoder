#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int l, r; cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; i++) ans++;
	cout << ans << endl;
	return 0;
}