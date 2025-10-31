#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define sz(x) (x).size()
typedef long long ll;
typedef vector<ll> vll;

const ll mod = 1e9+7;


vll topo(vector<vll> gr) {
    vll indeg(sz(gr)), q;
    for (auto &li : gr) for (ll x : li) indeg[x]++;
    rep (i, 0, sz(gr)) if (indeg[i] == 0) q.push_back(i);
    rep (j, 0, sz(q)) for (ll x : gr[q[j]])
        if (--indeg[x] == 0) q.push_back(x);
    return q;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, l;
    cin >> n >> l;

    vector<vll> adj(n, vll()), adjRev(n, vll());

    rep (i, 0, l) {
        ll k, v;
        cin >> k;
        rep (j, 0, k) {
            cin >> v;
            v--;
            adj[i].push_back(v);
            adjRev[v].push_back(i);
        }   
    }

    vll topoSort = topo(adj), emailsBefore(n, 0), emailsAfter(n, 0);
    emailsBefore[0] = 1;
    emailsAfter[0] = 1;

    for (ll v : topoSort) {
        for (ll u : adjRev[v]) {
            emailsBefore[v] = (emailsBefore[v] + emailsBefore[u]) % mod;
            emailsAfter[v] = max(emailsAfter[v], emailsAfter[u]); 
        }
    }

    ll beforeSum = 0, afterSum = 0;
    rep (i, l, n) {
        beforeSum = (beforeSum + emailsBefore[i] ) % mod;
        afterSum += emailsAfter[i];
    }

    cout << beforeSum << " " << afterSum << '\n';
}