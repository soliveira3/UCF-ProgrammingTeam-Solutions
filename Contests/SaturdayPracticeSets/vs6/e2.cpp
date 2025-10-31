#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(2*n));
    int tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            cin >> g[i][j];
            tot += (g[i][j] == 'C');
        }
    }

    vector<vector<char>> res = g;
    int r = n-1;
    int c = 0;
    int cnt = 0;
    if(tot % 2) {
        cout << "impossible\n";
        return 0;
    }
    while(r >= 0 && cnt < tot/2) {
        res[r][c] = 'A';
        cnt += (g[r][c] == 'C');
        if(cnt == tot/2) break;
        if(r) {
            res[r][c+1] = 'A';
            cnt += (g[r][c+1] == 'C');
        }
        r--;
        c++;
    }
    c = 0;
    for(int i = 0; i < n; i++) {
        c = n - 1 - i;
        while(c < 2*n-1 && g[i][c] != '#') {
            if(res[i][c] == 'A') {
                c++;
                continue;
            }
            if(cnt < tot/2) {
                res[i][c] = 'A';
                cnt += (g[i][c] == 'C');
            } else if(c == 2*n-2 && res[i][c-1] == 'A') {
                if(g[i][c] == 'C') {
                    cout << "impossible\n";
                    return 0;
                }
                res[i][c] = 'A';
            } else {
                res[i][c] = 'B';
            }
            c++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}