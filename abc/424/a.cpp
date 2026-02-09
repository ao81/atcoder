#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	set<int> a;
	int tmp;
	rep(i, 0, 3) {
		cin >> tmp;
		a.insert(tmp);
	}
	if (a.size() <= 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}