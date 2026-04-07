#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s, t;
	cin >> s >> t;
	int n = max(s.length(), t.length()), ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}