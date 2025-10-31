struct scc_info {
    int num_sccs;
    vector<int> scc_id;
};

scc_info scc(const vector<vector<int>>& adj) {
    int n = adj.size(), timer = 1, num_sccs = 0;
    vector<int> tin(n), scc_id(n, -1), node_stack;
    node_stack.reserve(n);
    auto dfs = [&](auto&& self, int u) -> int {
        int low = tin[u] = timer++;
        node_stack.push_back(u);
        for(auto v: adj[u])
            if(scc_id[v] < 0) 
                low = min(low, tin[v] ? tin[v] : self(self,v));
        if(tin[u] == low) {
            while(1) {
                int node = node_stack.back();
                node_stack.pop_back();
                scc_id[node] = num_sccs;
                if(node == u) break;
            }
            num_sccs++;
        }
        return low;
    };

    for(int i = 0; i < n; i++)
        if(!tin[i])
            dfs(dfs,i);
    return {num_sccs, scc_id};
}