#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> par,siz;
    dsu(int n) {
        siz = par = vector<int>(n,1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int a) {
        if(par[a] != a) par[a] = find(par[a]);
        return par[a];
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(siz[a] < siz[b]) swap(a,b);
        par[b] = a; siz[a] += siz[b];
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;
    cin >> n >> m >> k;
    dsu ds(n);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        ds.join(a,b);
    }

    vector<int> guys(n,1);
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        int cur = ds.find(i);
        if(ds.siz[cur] < k) {
            cout << "impossible\n";
            return 0;
        }
        res[i] = guys[cur]++;
        guys[cur] %= (k+1);
        if(!guys[cur]) guys[cur]++;
    }

    for(int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << '\n';
}

