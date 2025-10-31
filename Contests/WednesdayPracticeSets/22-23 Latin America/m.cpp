#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {1,-1,0,0};
vector<int> dc = {0,0,-1,1};
int c,r;


bool solve(string guy, vector<vector<int>> &g) {
    queue<array<int,2>> q;
    vector<vector<int>> vis(r,vector<int>(c));

    vector<vector<int>> poss(r,vector<int>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int bad = 0;
            for(int k = 0; k < c; k++) {
                if(g[i][(j+k)%c] && guy[k] == '1') {
                    // cout << "AT " << i << " " << j << " " << k << " " << g[i][(j+k)%c] << " " << guy[k] << " FOUND BAD\n";
                    bad = 1;
                    break;
                }
            }
            if(!bad) poss[i][j] = 1;
            if(poss[i][j] && !i) q.push({i,j});
        }
    }

    int f = 0;
    while(!q.empty()) {
        auto [u,v] = q.front(); q.pop();
        if(vis[u][v])continue;
        // cout << "AT " << u << " " << v << '\n';
        if(u == r-1) {
            return 1;
        }
        vis[u][v] = 1;
        for(int i = 0; i < 4; i++) {
            int du = u + dr[i];
            int dv = v + dc[i];
            if(dv < 0) dv = c-1;
            if(dv >= c) dv = dv%c;
            if(du < 0 || du >= r || !poss[du][dv])continue;
            q.push({du,dv});
        }
    }

    return 0;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> r >> c;
    vector<vector<int>> g(r,vector<int>(c));
    string guy;
    cin >> guy;
    for(int i = 0; i < r; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < c; j++) {
            g[i][j] = tmp[j]-'0';
        }
    }

    int works = solve(guy, g);
    reverse(guy.begin(), guy.end());
    works |= solve(guy, g);

    if (works) cout << "Y\n";
    else cout << "N\n";

    
}