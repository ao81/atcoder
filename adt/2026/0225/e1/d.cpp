#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int h, w, s;
	cin >> h >> w;
	string a = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rep(i, 0, h) {
		rep(j, 0, w) {
			cin >> s;
			cout << a[s];
		}
		cout << endl;
	}
	return 0;
}