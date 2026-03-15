#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s; cin >> s;
	ll ans = 0, i = 0;
	while (i < (int)s.length()) {
		char c = s[i];
		int cnt = 0;
		while (i + cnt < (int)s.length() && s[i + cnt] == c) cnt++;

		int j = i + cnt;
		if (j < (int)s.length() && s[j] == c + 1) {
			int cnt2 = 0;
			while (j + cnt2 < (int)s.length() && s[j + cnt2] == s[j]) cnt2++;
			ans += min(cnt, cnt2);
		}
		i += cnt;
	}
	cout << ans << endl;
	return 0;
}