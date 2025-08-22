#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
void djk(vll &dist, ll s, vector<vector<pll>> &adj)
{
    ll n = sz(dist);
    priority_queue<pll> pq;
    vector<bool> vis(n, false);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
 
        if (vis[u]) continue;
        vis[u] = true;
 
        for (auto x : adj[u])
        {
            ll v = x.first, w = x.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vector<pll>> adj, adjRev;
    adj.assign(n, vector<pll>());
    adjRev.assign(n, vector<pll>());
 
    rep(i, 0, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adjRev[v].push_back({u, w});
    }
 
 
    vll distStart(n, 1e15), distEnd(n, 1e15);
    djk(distStart, 0, adj);
    djk(distEnd, n-1, adjRev);
 
    ll mi = 1e15;
    rep(i, 0, n)
        for (auto ed : adj[i])
            mi = min(mi, distStart[i] + (ed.second / 2) + distEnd[ed.first]);
 
    cout << mi << '\n';
}