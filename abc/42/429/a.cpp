#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using pl = pair<int, int>;
using vl = vector<int>;
using vvl = vector<vector<int>>;

int main(void) {
	int n, m;
	cin >> n >> m;
	rep(i, 1, n+1) {
		if (i <= m) cout << "OK" << endl;
		else cout << "Too Many Requests" << endl;
	}
	return 0;
}