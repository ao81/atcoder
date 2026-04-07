#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s;
	cin >> s;
	bool oflag = 0;
	rep(i, 0, s.length()) {
		if (s[i] == '.' && oflag == 0) {
			s[i] = 'o';
			oflag = 1;
		} else if (s[i] == '#') {
			oflag = 0;
			continue;
		}
	}
	cout << s << endl;
	return 0;
}