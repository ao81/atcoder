#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;

int main(void) {
	int n, m;
	cin >> n >> m;
	vs s(n);
	rep(i, 0, n) cin >> s[i];
	set<vs> st;
	rep(i, 0, n - m + 1) {
		rep(j, 0, n - m + 1) {
			vs a(m);
			rep(k, 0, m) {
				a[k] = s[i + k].substr(j, m);
			}
			st.insert(a);
		}
	}
	cout << st.size() << endl;
	return 0;
}