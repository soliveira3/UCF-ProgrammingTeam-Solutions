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

int gridInd(int i, int j) { return i*1e3 + j; }

// int indTo

int main(){ 
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int x0,y0;
    cin >> x0 >> y0;

    vector<vector<int>> up(1e3+5, vector<int>(1e3+5,0)), down(1e3+5, vector<int>(1e3+5,0)), left(1e3+5, vector<int>(1e3+5,0)), right(1e3+5, vector<int>(1e3+5,0));
    for(int i = 0; i < n; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        for(int cx = min(x0,x1); cx < max(x0,x1); cx++) {
            up[cx][y0] = 1;
            down[cx][y0+1] = 1;
        }

        for(int cy = min(y0,y1); cy < max(y0,y1); cy++) {
            right[x0][cy] = 1;
            left[x0+1][cy] = 1;
        }
        x0 = x1;
        y0 = y1;
    }

    dsu ds(1e6+1e4);

    for(int i = 1; i <= 1e3; i++) {
        for(int j = 1; j <= 1e3; j++) {
            if(up[i][j] == 0) {
                ds.join(gridInd(i,j), gridInd(i+1,j));
            } 
            if(down[i][j] == 0) {
                ds.join(gridInd(i,j), gridInd(i-1,j));
            } 
            if(left[i][j] == 0) {
                ds.join(gridInd(i,j), gridInd(i,j-1));
            } 
            if(right[i][j] == 0) {
                ds.join(gridInd(i,j), gridInd(i,j+1));
            } 
        }
    }

    int outside = ds.find(0);
    cout << outside << '\n';
    int res = 0;
    for(int i = 0; i <= 1e3; i++) {
        for(int j = 0; j <= 1e3; j++) {
            if(i < 10 && j < 10) cout << ds.find(gridInd(i,j)) << ' ';
            if(ds.find(i) != outside) res = max(res, ds.siz[i]);
        }
        if(i < 10) cout << '\n';
    }

    cout << res << '\n';
}