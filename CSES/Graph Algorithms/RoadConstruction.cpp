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
 
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
 
        dsu.unite(a-1, b-1);
        cout << dsu.numSets << " " << dsu.largestSet << '\n';
    }
 
    return 0;
}