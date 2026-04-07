#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n;
	string s;
	cin >> n >> s;
	if (n >= 3 && s.substr(n - 3, 3) == "tea") {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}