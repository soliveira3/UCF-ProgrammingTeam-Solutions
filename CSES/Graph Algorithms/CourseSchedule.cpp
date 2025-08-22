#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
vll topoSort(const vector<vll> &gr)
{
    vll indeg(sz(gr)), q;
    for (auto& li : gr) for (int x : li) indeg[x]++;
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
    rep(j,0,sz(q)) for (int x : gr[q[j]])
    if (--indeg[x] == 0) q.push_back(x);
    return q;
}
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
    vector<vll> adj(n);
 
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
 
    vll topo = topoSort(adj);
 
    if ((ll)topo.size() < n)
        cout << "IMPOSSIBLE\n";
 
    else
    {
        rep (i, 0, n) cout << topo[i]+1 << " ";
        cout << '\n';
    }
}