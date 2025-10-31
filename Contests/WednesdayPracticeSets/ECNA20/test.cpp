struct mcmf {
    const ll inf = LLONG_MAX >> 2;
    struct edge {
        int v;
        ll cap, flow, cost;
    };
    int n;
    vector<edge> edges;
    vvi adj; vii par; vi seen;
    vector<ll> dist, pi;
    mcmf(int n) : n(n), adj(n), par(n), seen(n), dist(n), pi(n) {}
    void add_edge(int u, int v, ll cap, ll cost) {
        int idx = sz(edges);
        edges.push_back({v, cap, 0, cost});
        edges.push_back({u, cap, cap, -cost});
        adj[u].push_back(idx);
        adj[v].push_back(idx ^ 1);
    }
    bool find_path(int s, int t) {
        fill(all(dist), inf);
        fill(all(seen), 0);
        dist[s] = 0;
        __gnu_pbds::priority_queue<pair<ll,int>> pq;
        vector<decltype(pq)::point_iterator> its(n);
        pq.push({0,s});
        while(!pq.empty()) {
            auto [d,cur] = pq.top(); pq.pop(); d *= -1;
            seen[cur] = 1;
            if(dist[cur] < d) continue;
            for(int idx: adj[cur]) {
                auto [nxt, cap, f, wt] = edges[idx];
                ll nxtD = d + wt + pi[cur] - pi[nxt];
                if(f >= cap || nxtD >= dist[nxt] || seen[nxt]) continue;
                dist[nxt] = nxtD;
                par[nxt] = {cur, idx};
                if(its[nxt] == pq.end()) its[nxt] = pq.push({-nxtD, nxt});
                else pq.modify(its[nxt], {-nxtD, nxt});
            }
        }
        rep(i, 0, n) pi[i] = min(pi[i] + dist[i], inf);
        return seen[t];
    }
    pair<ll,ll> calc(int s, int t) {
        ll flow = 0, cost = 0;
        while(find_path(s,t)) {
            ll f = inf;
            for(int i, u, v = t; tie(u,i) = par[v], v != s; v = u)
                f = min(f, edges[i].cap - edges[i].flow);
            flow += f;
            for(int i, u, v = t; tie(u,i) = par[v], v != s; v = u)
                edges[i].flow += f, edges[i^1].flow -= f;
        }
        rep(i, 0, sz(edges)>>1)
            cost += edges[i<<1].cost * edges[i<<1].flow;
        return {flow,cost}
    }
}