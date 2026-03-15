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
	int a = 0, ab = 0, abc = 0;
	for (char c : s) {
		if (c == 'A') {
			a++;
		} else if (c == 'B') {
			if (a > 0) ab++, a--;
		} else if (c == 'C') {
			if (ab > 0) abc++, ab--;
		}
	}
	cout << abc << endl;
	return 0;
}