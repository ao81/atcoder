#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int isdigit(string s) {
	rep(i, 0, 3) {
		if (!isdigit(s[i])) return 0;
	}
	return 1;
}


int main(void) {
	string s;
	cin >> s;
	if (!isdigit(s)) {
		cout << "error" << endl;
		return 0;
	}
	int n = stoi(s);
	cout << n * 2 << endl;
	return 0;
}