#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)

using vi = vector<int>;

bool dfs(int a, int L, vector<vi> &g, vi& btoa, vi &A, vi &B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a])
        if (B[b] == L + 1) {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
                return btoa[b] = a, 1;
        }
    return 0;
}
int hopcroftKarp(vector<vi> &g, vi& btoa) {
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for (int a : btoa)
            if (a != -1) A[a] = -1;
        rep(a, 0, sz(g)) if (A[a] == 0) cur.push_back(a);
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur)
                for (int b : g[a]) {
                    if (btoa[b] == -1) {
                        B[b] = lay;
                        islast = 1;
                    } else if (btoa[b] != a && !B[b]) {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        rep(a, 0, sz(g)) res += dfs(a, 0, g, btoa, A, B);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<string, int> nameToInt;
    vector<string> intToName(n);

    vi lo(n, 0), hi(n, n-1);

    for (int i = 0; i < n; i++) {
        cin >> intToName[i];
        nameToInt[intToName[i]] = nameToInt.size();
    }

    vector<vector<int>> pos(n, vi(n, 1));
    vi vis(n);

    int r; cin >> r;
    while (r--) {
        int m, w; cin >> m >> w;
        w--;
        vector<int> arr(n);
        for (int i = 0; i < m; i++) {
            string s; cin >> s;
            int idx = nameToInt[s];
            arr[idx] = 1;
            lo[idx] = max(lo[idx], w);
        }

        for (int i = 0; i < n; i++) {
            if (!arr[i]) pos[w][i] = 0; 
        }
        vis[w] = 1;

    }
    vector<vi> g(n);



    for (int horse = 0; horse < n; horse++) {
        // cout << horse << ": " << lo[horse] + 1 << " " << hi[horse] + 1 << "\n";
        for (int place = lo[horse]; place < n; place++) {
            if (vis[place] && !pos[place][horse]) continue;
            // cout << intToName[horse] << " " << place + 1<< "\n";
            g[horse].push_back(place);
        }
    }
    
    // for (int j : g[0]) cout << j << " "; cout << "\n";
    // cout << vis[1] << "-" << pos[0][1] << "\n";

    // for (int i = 0; i < n; i++) {
    //     // cout << vis[i] << " ";

    //     for (int j = 0; j < n; j++) cout << pos[i][j] << " "; cout << "\n";
    // } 
    // cout << "\n";
    vi res(n, -1);
    hopcroftKarp(g, res);

    for (int i : res) cout << intToName[i] << " "; cout << "\n";
}