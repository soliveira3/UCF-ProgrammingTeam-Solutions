#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
vll dist;
vector<vll> adj;
 
void dfs(ll u, ll d)
{
    if (dist[u] != -1) return;
 
    dist[u] = d;
    for (auto v : adj[u]) dfs(v, d+1);
}
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
    dist.assign(n, -1);
 
    adj.assign(n, vll());
 
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    rep(i, 0, n) dfs(i, 0);
 
    bool possible = true;;
    rep(u, 0, n)
    {
        for (auto v : adj[u])
            if (dist[u]%2 == dist[v]%2) possible = false;
    }
 
    if (possible) rep(i, 0, n) cout << ((dist[i]%2) + 1) << " ";
    else cout << "IMPOSSIBLE";
 
    cout << '\n';
 
    return 0;
}