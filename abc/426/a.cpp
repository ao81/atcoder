#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	map<string, int> os = {
		{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}
	};
	string x, y;
	cin >> x >> y;
	if (os[x] >= os[y]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}