#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
ll INF = 1e16;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    vll dist(n, INF);
    vll vis(n, false);
    vector<vector<pll>> adj(n, vector<pll>());
 
    rep (i, 0, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
 
 
    priority_queue<pll> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
 
        if (vis[u]) continue;
        vis[u] = true;
        for (auto x : adj[u])
        {
            int v = x.first, w = x.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
 
    rep (i, 0, n) cout << dist[i] << ' ';
    cout << '\n';
 
    return 0;
}