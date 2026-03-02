#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s;
	cin >> s;
	int ans = 0, len = s.length();
	rep(i, 0, len) {
		int maxd = (len - 1 - i) / 2;
		rep(d, 1, maxd + 1) {
			if (s[i] == 'A' && s[i + d] == 'B' && s[i + 2 * d] == 'C') {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}