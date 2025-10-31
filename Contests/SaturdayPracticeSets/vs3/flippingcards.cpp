#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
    if(A[a] != L) return 0;
    A[a] = -1;
    for(int b: g[a]) 
        if(B[b] == L + 1) {
            B[b] = 0;
            if(btoa[b] == -1 || dfs(btoa[b], L+1, g, btoa, A, B))
                return btoa[b] = a, 1;
        }
    return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for(;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for(int a: btoa) if(a != -1) A[a] = -1;
        rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
        for(int lay = 1;; lay++) {
            bool isLast = 0;
            next.clear();
            for(int a: cur) for(int b: g[a]) {
                if(btoa[b] == -1) {
                    B[b] = lay;
                    isLast = 1;
                } else if(btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if(isLast) break;
            if(next.empty()) return res;
            for(int a: next) A[a] = lay;
            cur.swap(next);
        }
        rep(a,0,sz(g))
            res += dfs(a,0,g,btoa,A,B);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            int a,b;
            cin >> a >> b;
            --a;
            --b;
            g[i].push_back(a);
            g[i].push_back(b);
        }

        vector<int> btoa(2*n,-1);
        auto res = hopcroftKarp(g,btoa);
        int f = 0;
        for(int x: btoa) {
            if(x != -1) f++;
        }
        if(f == n) cout << "possible\n";
        else cout << "impossible\n";
    }
}