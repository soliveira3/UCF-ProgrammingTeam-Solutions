#include <bits/stdc++.h>
using namespace std;

int h,w;
vector<vector<int>> g;
int works(int siz) {
    vector<vector<int>> vis(h, vector<int>(w));
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(g[i][j] && !vis[i][j]) {
                if (i + siz > h || j + siz > w) return -1;
                for(int r = 0; r < siz; r++) {
                    for(int c = 0; c < siz; c++) {
                        if(!g[i+r][j+c] || vis[i+r][j+c]) return -1;
                        vis[i+r][j+c] = 1;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w;
    vector<int> pp(min(h,w)+5, -1);
    g = vector<vector<int>>(h+1, vector<int>(w+1));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            g[i][j] = c == '#';
        }
    }

    vector<vector<int>> aaaaa(h, vector<int>(w,0));
    int res = 1e9;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            aaaaa[i][j] = g[i][j];
            
            if(i) {
                if(!g[i][j] && aaaaa[i-1][j]) cout << aaaaa[i-1][j] << '\n', res = min(res, aaaaa[i-1][j]);
                aaaaa[i][j] = !g[i][j] ? 0 : aaaaa[i-1][j] + 1;
            }
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << aaaaa[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            aaaaa[i][j] = g[i][j];
            if(j) {
                if(!g[i][j] && aaaaa[i][j-1]) cout << aaaaa[i][j-1] << '\n', res = min(res, aaaaa[i][j-1]);
                aaaaa[i][j] = !g[i][j] ? 0 : aaaaa[i][j-1] + 1;
            }
        }
    }

    set<int, greater<int>> divs;
    divs.insert(1);
    if(res % 2 == 0) divs.insert(2);
    for(int i = 3; i*i <= res; i+=2) {
        if(res % i == 0) divs.insert(i);
    }

    for(int x: divs) {
        cout << x << '\n';
        if(!works(x)) {
            cout << x << '\n';
        }
    }
}