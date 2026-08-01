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

void yesno(bool ok) { cout << (ok ? "Yes" : "No") << "\n"; }

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

	int n, m;
	cin >> n >> m;

	vector<pl> edges(m);
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edges[i] = { a, b };
	}

	auto ok = [&](ll x, ll y) -> ll {
		for (auto [a, b] : edges) {
			if (a != x && b != x && a != y && b != y) {
				return false;
			}
		}
		return true;
	};

	auto cnt = [&](ll x) -> ll {
		for (auto [a, b] : edges) {
			if (a != x && b != x) {
				return ok(x, a) + ok(x, b);
			}
		}
		return n - 1;
	};

	auto [a, b] = edges[0];
	cout << cnt(a) + cnt(b) - ok(a, b) << "\n";
	return 0;
}
