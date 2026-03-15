#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<int>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n;
	cin >> n;
	vl a(n); for (auto& s: a) cin >> s;
	sort(all(a));
	cout << a[n-1] - a[0] << endl;
	return 0;
}