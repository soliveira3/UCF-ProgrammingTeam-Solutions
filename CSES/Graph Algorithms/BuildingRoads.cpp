#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
 
struct DisjointSet {
    vll size, par;
    ll numSets;
 
    DisjointSet (ll n) : par(n), size(n, 1) {
        iota(par.begin(), par.end(), 0);
        numSets = n;
    }
 
    ll find(ll x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
 
    void unite(ll a, ll b)
    {
        a = find(a), b = find(b);
        if (a == b) return;
        if (size[b] > size[a]) swap(a, b);
 
        par[b] = a;
        size[a] += size[b];
        numSets--;
    }
};
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    DisjointSet dsu(n);
 
    rep (i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        dsu.unite(u, v);
    }
 
 
    cout << dsu.numSets-1 << '\n';
    if (dsu.numSets-1 == 0) return 0;
 
    ll prevIndex = dsu.find(0);
    rep (i, 1, n)
    {
        ll prev = dsu.find(prevIndex);
        ll p = dsu.find(i);
        if (p != prev)
        {
            cout << prev+1 << " " << p+1 << '\n';
            dsu.unite(prev, p);
            prevIndex = p;
        }
    }
 
    return 0;
}