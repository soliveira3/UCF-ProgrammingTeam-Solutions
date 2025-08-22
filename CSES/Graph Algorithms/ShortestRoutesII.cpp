#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m, q;
    cin >> n >> m >> q;
    ll INF = 1e12;
 
    vector<vector<pair<ll, ll>>> adj(n, vector<pair<ll, ll>>());
    vector<vll> dis(n, vll(n, INF));
    rep(i, 0, n) dis[i][i] = 0;
 
    rep(i, 0, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }
 
    rep(i, 0, n) dis[i][i] = 0;
 
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
 
    rep(i, 0, q)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
 
        cout << ((dis[u][v] == INF) ? -1 : dis[u][v]) << '\n';
    }
}