#include <bits/stdc++.h>
using namespace std;

int h,w;
vector<vector<int>> g;
int works(int siz, BIT2D<int> bit) {
    vector<vector<int>> vis(h, vector<int>(w));
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(g[i][j] && !vis[i][j]) {
                if (i + siz > h || j + siz > w) return -1;
                // cout << i << " " <<  j << " " <<  i + siz - 1 << " " <<  j + siz- 1;
                // cout << " " << bit.query(i, j, i + siz - 1, j + siz - 1) << "\n";
                if (bit.query(i, j, i + siz - 1, j + siz - 1) != siz * siz) return -2;
                for(int r = 0; r < siz; r++) {
                    for(int c = 0; c < siz; c++) {
                        // cout << r << " " << c << "!!!\n";
                        if(!g[i+r][j+c] || vis[i+r][j+c]) return -1;
                        vis[i+r][j+c] = 1;
                        bit.add(i+r, j+c, -1);
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
    BIT2D<int> bit(h+2, w+2);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            g[i][j] = c == '#', bit.add(i, j, 1);
        }
    }

    // cout << works(3, bit) << "\n";

    int lo = 1;
    for(int i = 1; i <= min(h,w); i++) {
        // if(!pp[i] || works(i)) continue;
        if (pp[i] != -1) continue;
        int x = 1;
        for(int j = i; j <= min(h,w); j+=i) {
            if (x == 1) x = works(j, bit), lo = j;
            pp[j] = x;
        }
        i = lo;
    }
    int res = 1;
    for (int i = 0; i < pp.size(); i++) {
        if (pp[i] == 1) res = i;
    }
    cout << res << "\n";
}