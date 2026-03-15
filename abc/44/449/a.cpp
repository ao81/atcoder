#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	float d;
	cin >> d;
	d /= 2.0;
	cout << fixed << setprecision(10) << d * d * M_PI << endl;
	return 0;
}