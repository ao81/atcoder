#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size(), ans = 0;

	rep(l, 0, n) {
		int pos = l;
		bool end = true;
		rep(i, 0, m) {
			while (pos < n && s[pos] != t[i]) pos++;
			if (pos == n) { end = false; break; }
			pos++;
		}
		if (!end) ans += n - l;
		else ans += pos - 1 - l;
	}
	
	cout << ans << endl;
	return 0;
}