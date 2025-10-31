#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;
#define int ll

struct mcmf {
    const ll inf = LLONG_MAX >> 2;
    struct edge {
        int u,v;
        ll cap, flow, cost;
    };
    int n;
    vector<edge> edges;
    vvi adj; vii par; vi seen;
    vector<ll> dist, pi;
    mcmf(int n) : n(n), adj(n), par(n), seen(n), dist(n), pi(n) {}
    void add_edge(int u, int v, ll cap, ll cost) {
        int idx = sz(edges);
        edges.push_back({u, v, cap, 0, cost});
        edges.push_back({v, u, cap, cap, -cost});
        adj[u].push_back(idx);
        adj[v].push_back(idx ^ 1ll);
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
                auto [prv, nxt, cap, f, wt] = edges[idx];
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
                edges[i].flow += f, edges[i^1ll].flow -= f;
        }
        rep(i, 0, sz(edges)>>1ll)
            cost += edges[i<<1ll].cost * edges[i<<1ll].flow;
        return {flow,cost};
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<vl> distA(n, vl(n)), distB = distA;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <  n; j++) {
            cin >> distA[i][j] >> distB[i][j];
        }
    }

    vector<vl> distStA(n, vl(n)), distStB = distStA;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distStA[j][i] >> distStB[j][i]; 
        }
    }

    int bestPref = 0;
    int bestCost = 1e9;
    for (int pref = 0; pref <= n; pref++) {
        mcmf pp(4 * n +  2);
        int s = 4 * n, t = s + 1;
        // source -> guys
        for (int i = 0; i < n; i++) pp.add_edge(s, i, 1, 0);
        // guys -> gates
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pp.add_edge(i, n + j, 1, (j < pref) ? distA[i][j] : distB[i][j]);
            }
        }
        // gates -> gates'
        for (int i = 0; i < n; i++) pp.add_edge(n + i, 2 * n + i, 1, 0);

        // gates' -> stations
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pp.add_edge(2 * n + i, 3 * n + j, 1, (i < pref) ? distStA[i][j] : distStB[i][j]);
            }
        }

        for (int i = 3 * n; i < 4 * n; i++) pp.add_edge(i, t, 1, 0);

        int cur = pp.calc(s, t).second;
        if (cur < bestCost) {
            bestPref = pref;
            bestCost = cur;
        }
    }

    mcmf pp(4 * n +  2);
    int s = 4 * n, t = s + 1;
    // source -> guys
    for (int i = 0; i < n; i++) pp.add_edge(s, i, 1, 0);
    // guys -> gates
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pp.add_edge(i, n + j, 1, (j < bestPref) ? distA[i][j] : distB[i][j]);
        }
    }
    // gates -> gates'
    for (int i = 0; i < n; i++) pp.add_edge(n + i, 2 * n + i, 1, 0);

    // gates' -> stations
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pp.add_edge(2 * n + i, 3 * n + j, 1, (i < bestPref) ? distStA[i][j] : distStB[i][j]);
            // cout << "gate' " << i << " to station " << j << " -> " << ((i < bestPref) ? distStA[i][j] : distStB[i][j]) << "\n";
        }
    }

    for (int i = 3 * n; i < 4 * n; i++) pp.add_edge(i, t, 1, 0);


    cout << pp.calc(s, t).second << "\n";
    // cout << "PREFIXX" << bestPref << "\n";
    

    vector<int> gates(n), stations(n);
    for (auto edge : pp.edges) {
        if (!edge.flow || edge.cap <= 0) continue;
        if (edge.u < n) gates[edge.u] = edge.v - n;
        else if (edge.u >= 2 * n && edge.u < 3 * n) stations[edge.u - 2 * n] = edge.v - 3 * n;
        // else if (edge.u < 3 * n) gates2[edge.u-2*n] = edge.v - 3 * n;
    }

    for (int i = 0; i < n; i++) {
        // int guy = i;
        // int gate = gates[guy];
        // int gate2 = gates2[gate];
        // int station = stations[gate2];
        cout << i + 1 << " " << gates[i] + 1 << (gates[i] < bestPref ? "A" : "B") << " " << stations[gates[i]] + 1 << "\n";
        // cout << guy + 1 << " " << gate + 1 << (gate < bestPref ? "A" : "B") << " " << station + 1 << "\n";
    }
    
}