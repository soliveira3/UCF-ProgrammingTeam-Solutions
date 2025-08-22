#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
int k;
ll ans;
map<ll, ll> sizes, curSizes;
vector<int> subSize;
vector<vector<int>> adj;
vector<bool> removed;
 
int getSize(int u, int p)
{
    subSize[u] = 1;
    for (int v : adj[u])
        if (v != p && !removed[v])
            subSize[u] += getSize(v, u);
 
    return subSize[u];
}
 
int findCentroid(int u, int p, int n)
{
    for (int v : adj[u])
        if (v != p && !removed[v] && subSize[v] > n / 2)
            return findCentroid(v, u, n);
 
    return u;
}
 
void go(int u, int p, int d)
{
    if (d > k) return;
    ans += sizes[k - d];
    curSizes[d]++;
 
    for (int v : adj[u])
        if (v != p && !removed[v])
            go(v, u, d + 1);
}
 
void decomp(int node)
{
    int n = getSize(node, -1);
    if (n < k) return;
 
    int centroid = findCentroid(node, -1, n);
    removed[centroid] = true;
 
    // Checking paths that go through this node
    sizes.clear();
    sizes[0] = 1;
 
    for (int v : adj[centroid])
        if (!removed[v])
        {
            curSizes.clear();
            go(v, centroid, 1);
 
            for (auto pr : curSizes) sizes[pr.first] += pr.second;
        }
 
    if (ans == 0) return;
 
    // Checking the rest of the centroids
    for (int v : adj[centroid])
        if (!removed[v])
            decomp(v);
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n, v, u;
    cin >> n >> k;
 
    adj.assign(n, vector<int>());
    subSize.assign(n, 1);
    removed.assign(n, false);
 
    rep(i, 0, n - 1)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    decomp(0);
    cout << ans << '\n';
}