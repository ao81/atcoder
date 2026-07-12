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

template <class A, class B> bool chmin(A& a, const B& b) { return b < a ? (a = b, true) : false; }
template <class A, class B> bool chmax(A& a, const B& b) { return a < b ? (a = b, true) : false; }

template <class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto& e : v) is >> e;
	return is;
}
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	rep(i, 0, (ll)v.size()) os << (i ? " " : "") << v[i];
	return os;
}
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
	return os << p.first << " " << p.second;
}

#ifdef LOCAL
template <class T, class... Ts> void dbg_out(const T& a, const Ts &...b) {
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

	int n, k; cin >> n >> k;
	string s; cin >> s;

	int cur = 0, rp = -1, lk = 0, rk = 0;
	for (int i = 0; i < n; ) {
		if (s[i] == '1') {
			int j = i;
			while (j < n && s[j] == '1') j++;
			if (++cur == k - 1) rp = j - 1;
			if (cur == k) {
				lk = i;
				rk = j - 1;
				break;
			}
			i = j;
		} else i++;
	}

	for (int i = rp + 1; i <= rp + (rk - lk + 1); i++) s[i] = '1';
	for (int i = rp + (rk - lk + 1) + 1; i <= rk; i++) s[i] = '0';

	cout << s;
	return 0;
}
