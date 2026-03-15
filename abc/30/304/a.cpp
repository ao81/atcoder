#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n;
	cin >> n;
	vector<string> names(n);
	vector<pair<int, int>> a(n);
	rep(i, 0, n) {
		cin >> names[i] >> a[i].first;
		a[i].second = i;
	}
	int start = min_element(all(a))->second;
	rep(i, 0, n) cout << names[(start + i) % n] << endl;
	return 0;
}