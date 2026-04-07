#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, ans;
	cin >> n;
	if (1 <= n && n <= 125) ans = 4;
	else if (126 <= n && n <= 211) ans = 6;
	else ans = 8;
	cout << ans << endl;
	return 0;
}