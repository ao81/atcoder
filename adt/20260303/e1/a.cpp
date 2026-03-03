#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int a = 0, b = 0, in;
	rep(i, 0, 9) {
		cin >> in;
		a += in;
	}
	rep(i, 0, 8) {
		cin >> in;
		b += in;
	}
	cout << a - b + 1 << endl;
	return 0;
}