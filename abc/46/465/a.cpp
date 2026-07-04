#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	double a, b;
	cin >> a >> b;
	if (a > b * 2.0 / 3.0) cout << "Yes\n";
	else cout << "No" << endl;
	return 0;
}