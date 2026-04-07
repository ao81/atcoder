#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	vl n(3);
	rep(i, 0, 3) cin >> n[i];
	sort(all(n), greater());
	rep(i, 0, 3) cout << n[i];
	cout << endl;
	return 0;
}