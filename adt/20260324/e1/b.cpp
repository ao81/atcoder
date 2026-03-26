#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
	cout << pi.substr(0, n + 2) << endl;
	return 0;
}