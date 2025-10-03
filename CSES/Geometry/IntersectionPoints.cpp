#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
struct Tree
{
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
 
    void update(ll pos, T val)
    {
		for (s[pos += n] += val; pos /= 2;)
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
 
struct seg { ll x, y1, y2; };
bool comp(seg a, seg b) { return a.x < b.x; }
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n;
    cin >> n;
 
    vector<seg> vert;
    Tree st(2e6+10, 0);
 
    // xStart/End, Y to add to
    vector<pll> starts, ends;
 
    rep (i, 0, n)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6; x2 += 1e6;
        y1 += 1e6; y2 += 1e6;
 
        if (x1 == x2) vert.push_back({x1, y1, y2});
        else
        {
            starts.push_back({x1, y1});
            ends.push_back({x2, y1});
        }
    }
 
    sort(all(vert), comp);
    sort(all(starts));
    sort(all(ends));
 
    ll shi = 0, ehi = 0, ans = 0;
    for (int i = 0; i < sz(vert); i++)
    {
        // Start index updates
        while (shi < sz(starts) && starts[shi].first <= vert[i].x)
            st.update(starts[shi++].second, 1);
 
        // End index updates
        while (ehi < sz(ends) && ends[ehi].first <= vert[i].x)
            st.update(ends[ehi++].second, -1);
 
        ans += st.query(vert[i].y1, vert[i].y2+1);
    }
 
    cout << ans << '\n';
}