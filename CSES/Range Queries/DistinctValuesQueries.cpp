#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

// Kactl SegTree
struct Tree
{
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; }
	vector<T> s; ll n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}

    void update(ll pos, T val)
    {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}

    T query(ll b, ll e)
    {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, q;
    cin >> n >> q;
    vll a(n), sorted;

    // INPUT
    rep (i, 0, n) cin >> a[i];

    // Sorting for coordinate compression
    sorted = a;
    sort(all(a));
    sorted.erase(unique(all(sorted)), sorted.end());


}