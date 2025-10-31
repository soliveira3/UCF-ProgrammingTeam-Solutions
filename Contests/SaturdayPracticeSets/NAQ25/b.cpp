#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef long double ld;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r,c,n;
    cin >> r >> c >> n;

    queue<array<int,3>> q;
    for(int i = 0; i < n; i++) {
        int nr,nc;
        cin >> nr >> nc;
        --nr; --nc;
        q.push({i+1, nr, nc});
    }
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};

    vector<vector<vector<int>>> d(r, vector<vector<int>>(c));
    while(!q.empty()) {
        auto [idx, cr, cc] = q.front(); q.pop();
        if(d[cr][cc].size() == 2) continue;
        if(d[cr][cc].size() == 1 && d[cr][cc][0] != idx) d[cr][cc].push_back(idx);
        else if(d[cr][cc].size() == 1)continue;
        if(d[cr][cc].size() == 0) d[cr][cc].push_back(idx);
        for(int i = 0; i < 4; i++) {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            if(nr >= 0 && nr < r && nc >= 0 && nc < c) {
                q.push({idx,nr,nc});
            }
        }
    }

    for(int pp = 0; pp < 2; pp++) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << d[i][j][pp] << ' ';
            }
            cout << '\n';
        }
    }
    
}