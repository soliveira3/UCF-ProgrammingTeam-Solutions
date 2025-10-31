#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<char>> g(n, vector<char>(2*n-1));
    int tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            cin >> g[i][j];
            tot += (g[i][j] == 'C');
        }
    }

    if (tot % 2) {
        cout << "impossible\n";
        return 0;
    }

    int cntBot = 0, cntLeft = 0, cntRight = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (g[n-1][i] == 'C') cntBot++;
    }

    for (int r = 0; r < n; r++) {
        cntLeft += g[r][n-1-r] == 'C';
        cntRight += g[r][n-1+r] == 'C';
        if (r) {
            cntLeft += g[r][n-1-r+1] == 'C';
            cntRight += g[r][n-1+r-1] == 'C';
        }
    }
    // cout << cntBot << " " << cntLeft << " " << cntRight << "\n";
    if (cntBot > tot / 2 && cntLeft > tot / 2 && cntRight > tot / 2) {
        cout << "impossible\n";
        return 0;
    }

    vector<vector<char>> res = g;
    int cnt = 0;
    if (cntBot <= tot / 2) {
        cerr << "1\n";
        for (int c = 0; c < 2 * n - 1; c++) {
            cnt += g[n-1][c] == 'C';
            res[n-1][c] = 'A';
        }
        for (int r = n - 2; cnt < tot / 2 && r >= 0; r--) {
            cnt += g[r][n - 1 - r] == 'C';
            res[r][n-1-r] = 'A';
            if (cnt == tot / 2) break;
            cnt += g[r][n - 1 + r] == 'C';
            res[r][n-1+r] = 'A';
            if (cnt == tot / 2) break;
            for (int c = n - 1 - r + 1; c < n - 1 + r; c++) {
                cnt += g[r][c] == 'C';
                res[r][c] = 'A';
                if (cnt == tot / 2) break;
            }
            if (cnt == tot / 2) break;
        }
    } else {
        cerr << "2\n";
        int flag = false;
        if (cntLeft > tot / 2) {
            cerr << "3\n";
            flag = true;
            for (int r = 0; r < n; r++) {
                reverse(g[r].begin(), g[r].end());
                reverse(res[r].begin(), res[r].end());
            }
        } 

        for (int r = 0; r < n; r++) {
            cnt += g[r][n-1-r] == 'C';
            res[r][n-1-r] = 'A';
            if (r) {
                cnt += g[r][n-1-r+1] == 'C';
                res[r][n-1-r+1] = 'A';
            }
        }

        for (int c = 0; cnt < tot / 2 && c < 2 * n - 1; c++) {
            for (int r = 0; cnt < tot / 2 && r < n; r++) {
                if (res[r][c] == 'A' || res[r][c] == '#') continue;
                cnt += g[r][c] == 'C';
                res[r][c] = 'A';
            }
        }
        if (flag) {
            for (int r = 0; r < n; r++) {
                reverse(g[r].begin(), g[r].end());
                reverse(res[r].begin(), res[r].end());
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < 2 * n - 1; c++) {
            if (res[r][c] == '.' || res[r][c] == 'C') cout << 'B';
            else cout << res[r][c];
        }
        cout << "\n";
    }
}