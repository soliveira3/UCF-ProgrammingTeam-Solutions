#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vll> adj(n, vll());
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vll dist(n, -1);
    queue<ll> q;
    q.push(0);
    dist[0] = 1;
 
    vll path(n+1, -1);
    path[1] = 0;
 
    while (!q.empty())
    {
        ll u = q.front(); q.pop();
        path[dist[u]] = u;
        for (auto v : adj[u])
        {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
 
    if (dist[n-1] == -1) cout << "IMPOSSIBLE\n";
    else
    {
        cout << dist[n-1] << '\n';
 
        vll ans;
        ll node = n-1;
        ans.push_back(n-1);
        for (int i = dist[n-1]-1; i > 0; i--)
        {
            for (auto x : adj[node])
            {
                if (dist[x] == i)
                    node = x;
            }
            ans.push_back(node);
        }
 
        reverse(begin(ans), end(ans));
        for (auto x : ans) cout << x+1 << ' ';
        cout << '\n';
    }
 
    return 0;
}