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
	vl a(n + 1);
    vl b(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    
    bool ok = true;
    rep(i, 1, n + 1) {
        if (b[a[i]] != i) {
            ok = false;
        }
    }
    
    if (ok) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}