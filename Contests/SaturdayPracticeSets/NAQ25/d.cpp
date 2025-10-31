#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vector<pair<int, int>> dirs = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    queue<array<int, 3>> q;
    int startR, startC; cin >> startR >> startC;
    startR--; startC--;
    q.push({startR, startC, 1});
    int endR, endC; cin >> endR >> endC;
    endR--; endC--;

    vector<vvi> vis(n, vvi(m, vi(4)));
    vvi grid(n, vi(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            // gtcin >> ch;
            char x; cin >> x;
            grid[r][c] = x == '1';
            // if (ch == '1') for (int i = 0; i < 4; i++) vis[r][c][i] = 1;
        }
    }

    while (q.size()) {
        auto [r, c, d] = q.front();
        q.pop();
        if (r == endR && c == endC) {
            cout << "1\n";
            return 0;
        }
        if (vis[r][c][d]) continue;
        vis[r][c][d] = 1;
        
        int r1 = r + dirs[(d+3)%4].first;
        int c1 = c + dirs[(d+3)%4].second;
        int r2 = r + dirs[d].first;
        int c2 = c + dirs[d].second;
        // cout << r << " " << c << " " << d << ": " << r2 << " " << c2 << "\n";

        if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && !grid[r1][c1]) {
            if (!vis[r1][c1][(d+3)%4]) q.push({r1, c1, (d+3)%4});
        } else if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && !grid[r2][c2]) {
            if (!vis[r2][c2][d]) q.push({r2, c2, d});
        } else if (!vis[r][c][(d+1)%4]) {
            q.push({r, c, (d+1)%4});
        }
    }
    cout << "0\n";
    return 0;

}