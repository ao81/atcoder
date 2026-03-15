#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int s, a, b, x;
	cin >> s >> a >> b >> x;
	int c = a + b;
	int d = x / c;
	int e = x % c;
	int totalrun = (d * a) + min(e, a);
	int res = totalrun * s;
	cout << res << endl;
	return 0;
}