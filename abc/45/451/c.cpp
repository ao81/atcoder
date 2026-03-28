#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int q; cin >> q;
	map<int, int> tree;
	int total = 0;
	while (q--) {
		int t, h; cin >> t >> h;
		if (t == 1){
			tree[h]++;
			total++;
		} else {
			auto it = tree.upper_bound(h);
			for (auto i = tree.begin(); i != it; i++) {
				total -= i->second;
			}
			tree.erase(tree.begin(), it);
		}
		cout << total << endl;
	}
	return 0;
}