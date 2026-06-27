#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s; cin >> s;
	int e = count(all(s), 'E');
	int w = s.size() - e;
	if (e > w) cout << "East\n";
	else cout << "West\n";
	return 0;
}