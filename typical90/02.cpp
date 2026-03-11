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
	cin >> n;
	if (n % 2 != 0) return 0;

	auto isValid = [&](string s) -> bool {
		int a = 0;
		for (auto c : s) {
			if (c == '(') a++;
			else a--;
			if (a < 0) return false;
		}
		return (a == 0);
	};

	rep(i, 0, 1 << n) {
		string s = "";
		for (int j = n - 1; j >= 0; j--) {
			if (i & (1 << j)) s += ")";
			else s += "(";
		}
		if (isValid(s)) cout << s << endl;
	}
	
	return 0;
}