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
	string a = "22233344455566677778889999";
	rep(i, 0, n) {
		string s; cin >> s;
		cout << a[s[0] - 'a'];
	}
	cout << "\n";
	return 0;
}