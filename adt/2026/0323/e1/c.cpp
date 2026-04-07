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
	map<string, int> ans;
	rep(i, 0, n) {
		string s; cin >> s;
		ans[s]++;
	}
	int max = -1; string a;
	for (auto& [name, vote] : ans) {
		if (max < vote) {
			max = vote;
			a = name;
		}
	}
	cout << a << endl;
	return 0;
}