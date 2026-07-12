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
	char *c = &s[0];
	int cnt = -1;
	while (*c != '\0') {
		if (*c == '|') {
			if (cnt != -1) cout << cnt << " ";
			cnt = 0;
		}
		if (*c == '-') cnt++;
		c++;
	}
	return 0;
}