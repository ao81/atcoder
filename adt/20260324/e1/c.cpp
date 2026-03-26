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
	int i = 0, n = s.size();
	while (i < n && s[i] == 'A') i++;
	while (i < n && s[i] == 'B') i++;
	while (i < n && s[i] == 'C') i++;
	if (i == n) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}