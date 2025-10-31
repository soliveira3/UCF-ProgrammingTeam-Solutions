#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }

    int a,b;
    cin >> a >> b;
    --a;
    --b;
    queue<int> q;
    vector<int> vis1(n);
    vector<int> vis2(n);
    q.push(a);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(vis1[u]) continue;
        vis1[u] = 1;
        for(int v: g[u]) q.push(v);
    }

    q.push(b);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(vis2[u]) continue;
        vis2[u] = 1;
        for(int v: g[u]) q.push(v);
    }

    for(int i = 0; i < n; i++) if(vis1[i] && vis2[i]) {
        cout << "yes\n";
        cout << i+1 << '\n';
        return 0;
    }
    cout << "no\n";
}