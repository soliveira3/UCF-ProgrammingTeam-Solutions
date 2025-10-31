#include <bits/stdc++.h>
using namespace std;


struct scc_info {
    int num;
    vector<int> id;
};

scc_info scc(const vector<vector<int>>& adj) {
    int n = adj.size(), timer = 1, num = 0;
    vector<int> tin(n), id(n,-1), node_stack;
    node_stack.reserve(n);

    auto dfs = [&](auto&& self, int u) -> int {
        int low = tin[u] = timer++;
        node_stack.push_back(u);
        for(auto v: adj[u])
            if(id[v] < 0)
                low = min(low, tin[v] ? tin[v] : self(self,v));
        if(tin[u] == low) {
            while(1) {
                int node = node_stack.back();
                node_stack.pop_back();
                id[node] = num;
                if(node == u) break;
            }
            num++;
        }
        return low;
    };

    for(int i = 0; i < n; i++)
        if(!tin[i])
            dfs(dfs, i);
    return {num, id};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
    }

    auto info = scc(adj);

    if(info.num == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<set<int>> g(info.num);
    vector<int> indeg(info.num);
    for(int i = 0; i < n; i++) {
        for(auto v: adj[i]) {
            if(info.id[i] == info.id[v])continue;
            g[info.id[i]].insert(info.id[v]);
            indeg[info.id[v]]++;
        }
    }

    // vector<int> leaf(info.num);
    int noIndeg = 0;
    int leaf = 0;
    int root = 0;
    for(int i = 0; i < info.num; i++) {
        if(!g[i].size()) leaf++;
        if(!indeg[i]) noIndeg++;
        // if(!g[i].size() && !indeg[i]) root++;
        // if(noIndeg)
    }

    // cout << leaf << " " << noIndeg << '\n';
    int res = max(leaf, noIndeg);
    cout << res << '\n';
}