#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define rrep(i, l, r) for (ll i = (r) - 1; i >= (ll)(l); i--)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
template <class T> using V = vector<T>;
constexpr ll INF = 1ll << 60;

template <class A, class B> bool chmin(A &a, const B &b) { return b < a ? (a = b, true) : false; }
template <class A, class B> bool chmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }

template <class T> istream &operator>>(istream &is, vector<T> &v) {
	for (auto &e : v) is >> e;
	return is;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
	rep(i, 0, (ll)v.size()) os << (i ? " " : "") << v[i];
	return os;
}
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	return os << p.first << " " << p.second;
}

void yesno(bool ok) { cout << (ok ? "Yes" : "No") << "\n"; }

#ifdef LOCAL
template <class T, class... Ts> void dbg_out(const T &a, const Ts &...b) {
	cerr << a;
	((cerr << ", " << b), ...);
	cerr << "\n";
}
#define dbg(...) (cerr << "[L" << __LINE__ << "] " << #__VA_ARGS__ << " = ", dbg_out(__VA_ARGS__))
#else
#define dbg(...) ((void)0)
#endif

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string s; cin >> s;
	ll n = s.size(), ans = 0;

	rep(i, 0, 2 * n - 1) {
		ll l = i / 2;
		ll r = (i + 1) / 2;
		ll no = 0;
		while (l >= 0 && r < n) {
			if (s[l] != s[r]) no++;
			if (no >= 2) break;
			ans++;
			l--;
			r++;
		}
	}
	cout << ans << "\n";
	return 0;
}
