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
	vector<pair<string, int>> data(n);
	int mn = INT_MAX, idx = 0;
	rep(i, 0, n) {
		cin >> data[i].first >> data[i].second;
		if (mn > data[i].second) {
			mn = data[i].second;
			idx = i;
		}
	}

	rep(i, 0, n) {
		cout << data[idx].first << endl;
		if (++idx > n-1) idx = 0;
	}

	return 0;
}