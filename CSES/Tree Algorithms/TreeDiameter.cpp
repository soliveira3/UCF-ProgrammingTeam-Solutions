#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
ll n;
vll toLeaf;
vector<vll> edges;
vll maxDis;
 
void updateDistances(ll u, ll p, ll count)
{
    maxDis[u] = max(maxDis[u], count);
    for (auto v : edges[u])
        if (v != p) updateDistances(v, u, count + 1);
}
 
ll dfs(ll u, ll p)
{
    ll farthestNode = u, disN;
    for (auto v : edges[u])
    {
        if (v == p) continue;
 
        disN = dfs(v, u);
 
        if (toLeaf[v] + 1 > toLeaf[u])
        {
            toLeaf[u] = toLeaf[v] + 1;
            farthestNode = disN;
        }
    }
 
    return farthestNode;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    cin >> n;
    edges.assign(n, vll());
    toLeaf.assign(n, 0);
    maxDis.assign(n, 0);
 
    rep(i, 0, n-1)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    ll b = dfs(0, -1);
    toLeaf.assign(n, 0);
    ll c = dfs(b, -1);
 
    updateDistances(c, -1, 0);
    updateDistances(b, -1, 0);
    ll og = maxDis[c];
 
    cout << og << '\n';
 
    // rep(i, 0, n)
    //     cout << max(og, maxDis[i] + 1) << '\n';
 
    return 0;
}