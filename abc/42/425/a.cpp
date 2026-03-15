#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll f(int n) {
	if (n == 0) return 0;
	ll s = (n % 2 == 0) ? 1 : -1;
	return s * (n * n * n) + f(n - 1);
}

int main(void) {
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}