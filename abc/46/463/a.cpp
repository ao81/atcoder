#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int x, y;
	cin >> x >> y;
	int g = gcd(x, y);
	int w = x / g, h = y / g;
	if (w == 16 && h == 9) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}