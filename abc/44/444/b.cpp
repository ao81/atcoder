#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, k, res = 0;
	cin >> n >> k;
	rep (i, 1, n + 1) {
		int ii = i, sum = 0;
		while (ii > 0) {
			sum += ii % 10;
			ii /= 10;
		}
		if (sum == k) res++;
	}
	cout << res << endl;
	return 0;
}