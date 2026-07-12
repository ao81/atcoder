#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	int c[3] = { 0 };
	rep(i, 0, 6) {
		if (n % 10 >= 1 && n % 10 <= 3) c[n % 10 - 1]++;
		n /= 10;
	}
	if (c[0] == 1 && c[1] == 2 && c[2] == 3) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}