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
	rep(i, 0, (int)s.length() - 1) {
		if (s[i] == 'W' && s[i+1] == 'A') {
			s[i] = 'A', s[i+1] = 'C';
			if (i >= 1 && s[i-1] == 'W') i -= 2;
		}
	}
	cout << s << endl;
	return 0;
}