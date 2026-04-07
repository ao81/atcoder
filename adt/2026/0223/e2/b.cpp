#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s;
	cin >> s;
	int n = stoi(s);
	set<int> ans;
	rep(i, 0, 9) {
		ans.insert(n % 10);
		n /= 10;
	}
	rep(i, 0, 10) {
		if (ans.find(i) == ans.end()) {
			cout << i << endl;
			return 0;
		}
	}
}