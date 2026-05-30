#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	while (m != 0) {
		int x = n % m;
		m = x;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}