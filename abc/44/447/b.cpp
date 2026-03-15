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
	map<char, int> cnt;
	rep(i, 0, s.length()) cnt[s[i]]++;
	int max = 0;
	for (auto& c : cnt) {
		if (c.second > max) {
			max = c.second;
		}
	}
	for (auto& c : s) {
		if (cnt[c] != max) {
			cout << c;
		}
	}
	cout << endl;
	return 0;
}