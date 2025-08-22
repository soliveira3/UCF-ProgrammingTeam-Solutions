#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
template <class T>
T edmondsKarp(vector<unordered_map<ll, T>> &graph, ll source, ll sink)
{
    assert(source != sink);
    T flow = 0;
    vll par(sz(graph)), q = par;
 
    for (;;)
    {
        fill(all(par), -1);
        par[source] = 0;
        ll ptr = 1;
        q[0] = source;
        rep(i, 0, ptr)
        {
            ll x = q[i];
            for (auto e : graph[x])
            {
                if (par[e.first] == -1 && e.second > 0)
                {
                    par[e.first] = x;
                    q[ptr++] = e.first;
                    if (e.first == sink) goto out;
                }
            }
        }
        return flow;
    out:
 
        T inc = numeric_limits<T>::max();
        for (ll y = sink; y != source; y = par[y])
            inc = min(inc, graph[par[y]][y]);
 
        flow += inc;
 
        for (ll y = sink; y != source; y = par[y])
        {
            ll p = par[y];
            if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
            graph[y][p] += inc;
        }
    }
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m, a, b, c;
    cin >> n >> m;
 
    vector<unordered_map<ll, ll>> mp(n, unordered_map<ll, ll>());
 
    rep (i, 0, m)
    {
        cin >> a >> b >> c;
        a--; b--;
        mp[a][b] += c;
    }
 
    cout << edmondsKarp(mp, 0, n-1) << '\n';
}

