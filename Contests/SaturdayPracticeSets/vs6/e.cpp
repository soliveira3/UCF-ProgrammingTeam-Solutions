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
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(2*n-1));
    int tot = 0;
    int cntBot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            cin >> g[i][j];
            tot += (g[i][j] == 'C');
            cntBot += (i == n - 1) && g[i][j] == 'C';
        }
    }

    vector<vector<char>> res = g;
    if(tot % 2) {
        cout << "impossible\n";
        return 0;
    }
    
    if (cntBot == n / 2) {
        for (int r = 0; r < n - 1; r++) {
            for (int c = 0; c < 2 * n - 1; c++) {
                if (res[r][c] == '.' || res[r][c] == 'C') res[r][c] = 'B';
            }
        }
        for (int c = 0; c < 2 * n - 1; c++) res[n - 1][c] = 'A';
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < 2 * n - 1; c++) {
                cout << res[r][c];
            }
            cout << "\n";
        }
        return 0;
    }
    else if (cntBot <= n / 2) {
        int cnt = 0;
        for (int r = n - 1; r >= 0; r--) {
            cnt += g[r][n - 1 - r] == 'C';
            res[r][n-1-r] = 'A';
            if (cnt == n / 2) break;
            cnt += g[r][n - 1 + r] == 'C';
            res[r][n-1+r] = 'A';
            if (cnt == n / 2) break;
            for (int c = n - 1 - r + 1; c < n - 1 + r; c++) {
                cnt += g[r][c] == 'C';
                res[r][c] = 'A';
                if (cnt == n / 2) break;
            }
            if (cnt == n / 2) break;
        }
    } else {
        int first = g.back()[0] == 'C';
        int first2 = g.back()[1] == 'C';
        int last = g.back().back() == 'C';
        int last2 = g.back()[g.back().size()-2] == 'C';
        int top = g[0][n-1] == 'C';
        int top2 = g[1][n-1] == 'C';
        
        if (tot == 6 && (first + first2 + last + last2 + top + top2) == 6) {
            cout << "impossible\n";
            return 0;
        }
        int cnt = 0;
        if (first && last) {
            // FUCK THIS CASE
            vector<vector<char>> tmp = res;
            for (int c = 0; c < n; c++) {
                for (int r = n - 1; r >= 0 && g[r][c] != '#'; r--) {
                    cnt += g[r][c] == 'C';
                    tmp[r][c] = 'A';
                    if (cnt >= tot/2) {
                        if (c == n - 1 && r == 1) {
                            cnt += g[0][c] == 'C';
                            tmp[0][c] = 'A'; 
                        }
                        break;
                    }
                }
                if (cnt >= tot / 2) break;
            }
            if (cnt == tot / 2) {
                res = tmp;
            } else {
                cnt = 0;
                for (int c = 2 * n - 2; c >= n - 1; c--) {
                    for (int r = n - 1; r >= 0 && g[r][c] != '#'; r--) {
                        cnt += g[r][c] == 'C';
                        res[r][c] = 'A';
                        if (cnt >= tot/2) {
                            if (c == n - 1 && r == 1) {
                                cnt += g[0][c] == 'C';
                                tmp[0][c] = 'A'; 
                            }
                            break;
                        }
                    }
                    if (cnt >= tot / 2) break;
                }
            }
        } else if (!last) {
            for (int c = 0; c < 2 * n - 1; c++) {
                cnt += g.back()[c] == 'C';
                res.back()[c] = 'A';
                if (cnt == n / 2) break;
            }
        } else {
            for (int c = 2 * n - 2; c >= 0; c--) {
                cnt += g.back()[c] == 'C';
                res.back()[c] = 'A';
                if (cnt == n / 2) break;
            }
        } 
    }

    int cntA = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < 2 * n - 1; c++) {
            cntA += g[r][c] == 'C' && res[r][c] == 'A';
        }
    }

    if (cntA * 2 != tot) {
        cout << "impossible\n";
        return 0;
    }

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            if (res[i][j] == '.' || res[i][j] == 'C') res[i][j] = 'B';
        }
    }

    dsu ds(n*2*n+1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            if(res[i][j] == '#') continue;
            if(res[i][j] != 'A' && res[i][j] != 'B') {
                cout << "impossible\n";
                return 0;
            }
            
            for(int k = 0; k < 4; k++) {
                int dr = i + dx[k];
                int dc = j + dy[k];
                if(dr >= n || dr < 0 || dc >= 2*n-1 || dc < 0) continue;
                                    // cout << "AT " << dr*(2*n-1)+dc << " " << i*(2*n-1)+j << " " << res[i][j] << " " << res[dr][dc] << '\n';

                // cout << i << " " << j << " -> " << dr << " " << dc << "\n";
                if(res[dr][dc] == res[i][j]) {
                    ds.join(i*(2*n-1)+j, dr*(2*n-1)+dc);
                    // cout << "JOINING " << dr*(2*n-1)+dc << " " << i*(2*n-1)+j << " " << res[i][j] << " " << res[dr][dc] << '\n';
                }
            }
        }
    }

    int a = -1;
    int b = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            if(res[i][j] == '#')continue;
            if(res[i][j] == 'A' && a != -1 && ds.find(i*(2*n-1)+j) != a) {
                cout << "impossible\n";
                return 0;
            } 
            if(a == -1 && res[i][j] == 'A') a = ds.find(i*(2*n-1)+j);

            if(res[i][j] == 'B' && b != -1 && ds.find(i*(2*n-1)+j) != b) {
                cout << "impossible\n";
                return 0;
            } 
            if(b == -1 && res[i][j] == 'B') b = ds.find(i*(2*n-1)+j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}