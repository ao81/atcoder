#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a != b && b == c) {
	  cout << "Yes\n";
	} else {
	  cout << "No\n";
	}
	return 0;
}