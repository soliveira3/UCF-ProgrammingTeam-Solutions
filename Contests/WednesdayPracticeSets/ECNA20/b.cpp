#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r,c;
    cin >> r >> c;
    vector<vector<char>> g(r,vector<char>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> g[i][j];
        }
    }

    int k;
    string s;
    cin >> k >> s;
    queue<array<int,5>> q;
    vector<vector<vector<vector<vector<int>>>>> vis(8, vector<vector<vector<vector<int>>>>(r+3, vector<vector<vector<int>>>(c+3, vector<vector<int>>(k+1, vector<int>(s.size()+3)))));
    vector<int> dx = {1,-1,0,0,-1,-1,1,1};
    vector<int> dy = {0,0,1,-1,1,-1,1,-1};
    int f = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(s[0] == g[i][j]) {
                f = 1;
                for(int dir = 0; dir < 8; dir++) { 
                    if(i + dx[dir] < 0 || j + dy[dir] < 0 || i + dx[dir] >= r || j + dy[dir] >= c || g[i + dx[dir]][j + dy[dir]] != s[1])continue;
                    q.push({i + dx[dir],j + dy[dir],2,0,dir});
                }
            }
        }
    }

    if(s.size() == 1 && k) {
        cout << "No\n";
        return 0;
    } else if (s.size() == 1 && !k) {
        if(f) cout << "Yes\n";
        else cout << "No\n";
        return 0;
    }

    while(!q.empty()) {
        auto [row, col, idx, kink, dir] = q.front();
        q.pop();
        if(vis[dir][row][col][kink][idx])continue;
        vis[dir][row][col][kink][idx] = 1;

        if(idx == s.size() && kink == k) {
            cout << "Yes\n";
            return 0;
        }

        for(int i = 0; i < 8; i++) {
            int dr = row + dx[i];
            int dc = col + dy[i];
            if(dr < 0 || dc < 0 || dr >= r || dc >= c || g[dr][dc] != s[idx])continue;
            if(i != dir && kink == k) continue;
            q.push({dr,dc,idx+1, kink + (dir != i), i});
        }
    }
    
    cout << "No\n";
    return 0;
}