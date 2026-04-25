#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    ll ans = 0;
    rep(h1, 0, h) rep(h2, h1, h) rep(w1, 0, w) rep(w2, w1, w) {
        bool ok = true;
        rep(i, h1, h2+1) rep(j, w1, w2+1) {
            if (s[i][j] != s[h1+h2-i][w1+w2-j]) {
                ok = false;
            }
        }
        if (ok) ans++;
    }

    cout << ans << endl;
    return 0;
}
