#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5+5, maxk = 20;
int lift[maxn][maxk], depth[maxn];
ll nums[maxn];
vector<int> adj[maxn];
vector<vector<vector<int>>> guys;

void dfs(int u, int root, int p = -1, int d = 1) {
    depth[u] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        lift[v][0] = u;
        dfs(v, root, u, d + 1);
    }
    while (guys[root].size() <= d) guys[root].push_back({});
    if (nums[u]) guys[root][d].push_back(u);
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = 0; i < maxk; i++) if (diff & (1 << i)) v = lift[v][i];
    if (u == v) return u;

    for (int i = maxk - 1; i >= 0; i--) {
        if (lift[u][i] != lift[v][i]) u = lift[u][i], v = lift[v][i];
    }
    return lift[u][0];

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<ll>> ans(n);
    guys = vector<vector<vector<int>>>(n);

    for (int i = 1; i < n; i++) cin >> nums[i];

    vector<int> roots;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (min(u, v) == 0) roots.push_back(max(u,v)), lift[max(u,v)][0] = max(u,v);
        else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int root : roots) {
        dfs(root, root);
    }

    for (int k = 1; k < maxk; k++) {
        for (int u = 0; u < n; u++) {
            lift[u][k] = lift[lift[u][k-1]][k-1];
        }
    }

    ll bestVal = 0;
    int bestTime = -1;

    // for (int root = 0; root < n; root++) {
    //     cout << root + 1 << "->:\n";
    //     for (int lvl = 0; lvl < guys[root].size(); lvl++) {
    //         cout << lvl << ": ";
    //         for (int i : guys[root][lvl]) cout << i + 1 << " ";
    //         cout << "\n";
    //     }.
    // }

    for (int root = 0; root < n; root++) {
        for (int lvl = 0; lvl < guys[root].size(); lvl++) {
            if (guys[root][lvl].size() == 0) continue;
            if (guys[root][lvl].size() == 1) {
                if (nums[guys[root][lvl][0]] > bestVal) {
                    bestVal = nums[guys[root][lvl][0]];
                    bestTime = 1;
                } else if (bestVal == nums[guys[root][lvl][0]]) {
                    bestTime = 1;
                }
                continue;
            }
            ll val = 0;
            for (int guy : guys[root][lvl]) val += nums[guy];
            if (val < bestVal) continue;

            int node = lca(guys[root][lvl][0], guys[root][lvl][1]);
            for (int i = 2; i < guys[root][lvl].size(); i++) {
                node = lca(node, guys[root][lvl][i]);
            }
            int t = lvl - depth[node] + 1;
            // cout << node + 1 << " " << depth[node] << " " << lvl << "\n";
            // cout << t << "\n";
            if (val > bestVal) {
                bestVal = val;
                bestTime = t;
            } else {
                bestTime = min(bestTime, t);
            }
        }
    }

    // assert(bestTime >= 0);
    cout << bestVal << " " << bestTime << "\n";


}