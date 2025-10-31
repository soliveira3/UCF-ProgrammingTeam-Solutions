#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()
#define rep(i,a,b) for(int i = a; i < (int)b; ++i)
#define int long long
typedef vector<int> vi;


vector<int> depth;
vector<vector<int>> adj;
map<string, int> idx;
vector<string> name;

void dep(int u, int p, int d) {
    depth[u] = d;
    for(int v: adj[u]) {
        if(v == p)continue;
        dep(v,u,d+1);
    }
}

vector<vi> treeJump(vi& P) {
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d,P);
    rep(i,1,d) rep(j,0,sz(P))
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps) {
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int lca(vector<vi>& tbl, int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);
    a = jmp(tbl, a, depth[a]-depth[b]);
    if(a == b) return a;
    for(int i = sz(tbl); i--;) {
        int c = tbl[i][a], d= tbl[i][b];
        if(c != d) a = c, b = d;
    }
    return tbl[0][a];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,q;
    cin >> N >> q;
    int cnt = 0;
    vector<int> indeg(105);
    depth = vector<int>(105);
    name = vector<string>(105);
    adj = vector<vector<int>>(105);
    vector<int> parents(105);
    for(int i = 0; i < N; i++) {
        string nm;
        int M;
        cin >> nm >> M;
        if(!idx.count(nm)) idx[nm] = cnt, name[cnt++] = nm;
        for(int v = 0; v < M; v++) {
            string other;
            cin >> other;
            if(!idx.count(other)) idx[other] = cnt, name[cnt++] = other;
            parents[idx[other]] = idx[nm];
            indeg[idx[other]]++;
            adj[idx[nm]].push_back(idx[other]);
            adj[idx[other]].push_back(idx[nm]);
        }
    }

    int root = -1;
    for(int i = 0; i < cnt; i++) if(!indeg[i]) root = i;
    assert(root != -1);

    dep(root, -1, 0);
    auto tbl = treeJump(parents);

    for(int i = 0; i < q; i++) {
        string a,b;
        cin >> a >> b;
        int l = lca(tbl, idx[a], idx[b]);
        int n = depth[idx[a]] - depth[l];
        int m = depth[idx[b]] - depth[l];

        vector<string> suffix =
        {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "th", "th", "th", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",
        "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th",};


        if (min(m,n) == 0) {
            if (m > n){
                swap(n, m);
                swap(a, b);
            }
        
            // child of a
            if (n == 1)
                cout << a << " is the child of " << b << '\n';
            // grandchild
            else  {
                cout << a << " is the ";
                for (int x = 0; x < n-2; x++) cout << "great ";
                cout << "grandchild of " << b << '\n';
            }
        }

        else if (n == m) {
            if (n == 1)
                cout << a << " and " << b << " are siblings\n";

            else
                cout << a << " and " << b << " are " << n-1 << suffix[(n-1)] << " cousins\n";
        }

        else {
            if (m > n)
                swap(n, m);
    
            cout << a << " and " << b << " are " << m-1 << suffix[(m-1)] << " cousins, " << (n-m) << " time" << ((n-m == 1) ? " " : "s ") << "removed\n";
        }

        // rep (i, 0, 100) cout << i << ": " << suffix[i] << '\n';  
    }

}