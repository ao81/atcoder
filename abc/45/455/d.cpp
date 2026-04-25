#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, q; cin >> n >> q;

	vl nxt(n + 1, -1);
	vl prv(n + 1, -1);

	rep(i, 0, q) {
		int c, p;
		cin >> c >> p;

		if (prv[c] != -1) {
			nxt[prv[c]] = -1;
		}

		prv[c] = p;
		nxt[p] = c;
	}

	vl ans(n + 1, 0);

	rep(i, 1, n + 1) {
		if (prv[i] == -1) {
			int count = 0;
			int curr = i;
			while (curr != -1) {
				count++;
				curr = nxt[curr];
			}
			ans[i] = count;
		}
	}

	rep(i, 1, n + 1) cout << ans[i] << " ";
	cout << "\n";

	return 0;
}