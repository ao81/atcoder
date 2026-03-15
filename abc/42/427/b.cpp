#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int f(int x) {
	int s = 0;
	while (x > 0) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main(void) {
	int n; cin >> n;
	vector<int> a(n + 1);
	a[0] = 1;
	rep(i, 1, n + 1) {
		rep(j, 0, i) {
			a[i] += f(a[j]);
		}
	}
	cout << a[n] << endl;
	return 0;
}