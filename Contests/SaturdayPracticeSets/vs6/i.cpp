#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (adj[v].count(u)) {
            adj[v].erase(u);
        } else {
            adj[u].insert(v);
        }
    }

    vector<int> deg(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            deg[v]++;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] > deg[res]) {
            res = i;
        }
    }

    cout << res + 1 << " " << deg[res] << "\n";
}