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
	string s; cin >> s;
	int i = 0;
	while (i < n && s[i] == 'o') i++;
	cout << s.substr(i) << '\n';
	return 0;
}