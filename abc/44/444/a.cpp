#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, res = 1;
	cin >> n;
	int dig = n % 10;
	rep(i, 0, 3) {
		int a = n % 10;
		if (dig != a) res = 0;
		n /= 10;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}