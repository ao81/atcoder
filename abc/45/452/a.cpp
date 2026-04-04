#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int m, d; cin >> m >> d;
	vector<pl> g = {{1, 7}, {3, 3}, {5, 5}, {7, 7}, {9, 9}};
	bool found = false;
	for (auto p : g) {
		if (p.first == m && p.second == d) found = true;
	}
	if (found) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}