#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	ll sum = 0, sum2 = 0;
	rep(i, 0, n) {
		int a; cin >> a;
		sum += a;
		sum2 += a * a;
	}
	cout <<  (sum * sum - sum2) / 2 << endl;
	return 0;
}

/*
	∑AiAj = ((∑Ai)² - ∑(Ai)²) / 2
*/