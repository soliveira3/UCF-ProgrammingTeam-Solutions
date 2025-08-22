#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct DisjointSets
{
    vector<ll> par, rank, sz;
    ll numSets, largestSet;
 
    DisjointSets (ll size) : par(size), rank(size, 0), sz(size, 1) {
        numSets = size;
        largestSet = 1;
        iota(par.begin(), par.end(), 0);
    }
 
    ll find(ll x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
 
    bool unite(ll x, ll y) {
        x = find(x), y = find(y);
        if (x == y) { return false; }
        if (rank[x] > rank[y]) swap(x, y);
 
        par[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        sz[y] += sz[x];
 
        numSets--;
        largestSet = max(largestSet, sz[y]);
 
        return true;
    }
 
};
 
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    DisjointSets dsu(n);
    vector<tuple<ll, ll, ll>> edges(m);
 
    for (ll i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        edges[i] = {w, a, b};
    }
 
    sort(edges.begin(), edges.end());
 
    ll totalWeight = 0;
    for (int i = 0; i < m; i++)
    {
        ll w, a, b;
        tie(w, a, b) = edges[i];
 
        if (dsu.find(a) == dsu.find(b)) continue;
 
        dsu.unite(a, b);
        totalWeight += w;
    }
 
    if (dsu.numSets != 1) cout << "IMPOSSIBLE\n";
    else cout << totalWeight << '\n';
 
 
    return 0;
}