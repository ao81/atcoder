#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

string f(const string& s) {
	string res;

	for (char c : s) {
		res.push_back(c);
		int n;
		while ((n = res.size()) >= 4 && res[n-1] == ')' && res[n-2] == 'x' && res[n-3] == 'x' && res[n-4] == '(') {
			rep(i, 0, 4) res.pop_back();
			res += "xx";
		}
	}

	return res;
}

int main(void) {
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a >> b;
		if (f(a) == f(b)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}