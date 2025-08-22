#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
ll n;
vector<vll> edges;
vll subTrees;
 
void dfs(ll u, ll p)
{
    subTrees[u] = 1;
    for (auto v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            subTrees[u] += subTrees[v];
        }
    }
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    cin >> n;
    edges.assign(n, vll());
    subTrees.assign(n, 0);
 
 
    rep(i, 1, n)
    {
        ll x; cin >> x; x--;
        edges[x].push_back(i);
        edges[i].push_back(x);
    }
 
    dfs(0, -1);
 
    rep(i, 0, n) cout << subTrees[i]-1 << " ";
    cout << '\n';
 
    return 0;
}