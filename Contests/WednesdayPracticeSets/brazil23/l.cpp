#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<pair<int, int>, int> edge_to_idx;
vector<vector<int>> adj;
vector<int> color;

vector<ll> ans;

void update(map<int, int> &a, vector<int> &totColors, int key, int delta, ll &curAns) {
    // updated a with delta, keeps answer
    // cout << curAns << "---> " << key + 1 << " " << a[key] << " !!! " << totColors[key] - a[key] << "\n";
    if (a.count(key)) curAns -= (ll)a[key] * (totColors[key]-a[key]);
    a[key] += delta;
    if (a[key] == 0) a.erase(key);
    if (a.count(key)) curAns += (ll)a[key] * (totColors[key]-a[key]);
    // cout << key + 1 << " " << a[key] << " ??? " << totColors[key] - a[key] << "\n";
}

void dfs(int u, int p, vector<int> &totColors, map<int, int> &botColors, ll &curAns) {
    
    for (int v : adj[u]) {
        if (v == p) continue;

        map<int, int> newColors;
        ll newAns = 0;
        dfs(v, u, totColors, newColors, newAns);
        if (newColors.size() > botColors.size()) {
            swap(newColors, botColors);
            swap(newAns, curAns);
        }
        for (auto [key, val] : newColors) {
            // botColors[key] += val;
            update(botColors, totColors, key, val, curAns);
        }
    }

    update(botColors, totColors, color[u], 1, curAns);    
    
    // cout << "at node " << u  + 1 << " " << curAns << "\n";
    // cout << "botColors: ";
    // for (auto [a, b] : botColors) cout << a + 1 << ": " << b << ", ";
    // cout << "\n";
    // calc
    if (p != -1) {
        ans[edge_to_idx[{min(u,p),max(u,p)}]] = curAns;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    
    color = vector<int>(n);
    ans = vector<ll>(n-1);
    map<int, int> botColors;
    vector<int> totColors(n);
    // colors
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        color[i]--;
        totColors[color[i]]++;
    }

    // edges
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_to_idx[{min(u,v), max(u,v)}] = edge_to_idx.size();
    }
    int r = -1;
    for (int x = 0; x < n; x++) {
        if (adj[x].size() == 1) {
            r = x;
            break;
        }
    }
    assert(r >= 0);
    ll curAns = 0;
    dfs(r, -1, totColors, botColors, curAns);

    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}