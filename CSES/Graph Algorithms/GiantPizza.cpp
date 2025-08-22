#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
struct TwoSat
{
    ll N;
    vector<vll> gr;
    vll values;
 
    TwoSat(ll n = 0) : N(n), gr(2*n) {}
 
    void either(ll f, ll j)
    {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
 
    vll val, comp, z; ll time = 0;
    ll dfs(ll i)
    {
        ll low = val[i] = ++time, x; z.push_back(i);
        for(ll e : gr[i]) if (!comp[e])
        low = min(low, val[e] ?: dfs(e));
        if (low == val[i]) do {
        x = z.back(); z.pop_back();
        comp[x] = low;
        if (values[x>>1] == -1)
        values[x>>1] = x&1;
        } while (x != i);
        return val[i] = low;
    }
 
    bool solve()
    {
        values.assign(N, -1);
        val.assign(2*N, 0); comp = val;
        rep(i,0,2*N) if (!comp[i]) dfs(i);
        rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
        return 1;
    }
};
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll m, n;
    cin >> m >> n;
 
    TwoSat twoSat(n);
 
    rep (i, 0, m)
    {
        char c1, c2;
        ll u, v;
        cin >> c1 >> u >> c2 >> v;
        u--; v--;
 
        if (c1 == '-') u = ~u;
        if (c2 == '-') v = ~v;
 
        twoSat.either(u, v);
    }
 
    bool pos = twoSat.solve();
 
    if (pos)
    {
        rep (i, 0, n)
            cout << ((twoSat.values[i]) ? "+ " : "- ");
        cout << '\n';
    }
 
    else cout << "IMPOSSIBLE\n";
}