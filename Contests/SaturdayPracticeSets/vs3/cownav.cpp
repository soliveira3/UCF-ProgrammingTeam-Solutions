#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int maxn = 20;
int dist[maxn][maxn][maxn][maxn][4], grid[maxn][maxn];
vector<pii> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch; cin >> ch;
            grid[i][j] = ch == 'H';
        }
    }

    queue<array<int, 5>> q;
    q.push({n - 1, 0, n - 1, 0, 0});

    // cout << "HELLO" << endl;

    while (q.size()) {
        auto [r1, c1, r2, c2, d1] = q.front();
        q.pop();
        // cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << d1 << " " << dist[r1][c1][r2][c2][d1] << endl;

        if (r1 == 0 && c1 == n - 1 && r2 == 0 && c2 == n - 1) {
            cout << dist[r1][c1][r2][c2][d1] << "\n";
            return 0;
        }

        int d2 = (d1 + 1) % 4;

        // left
        if (!dist[r1][c1][r2][c2][(d1+3)%4]) {
            dist[r1][c1][r2][c2][(d1+3)%4] = dist[r1][c1][r2][c2][d1] + 1;
            q.push({r1,c1,r2,c2,(d1+3)%4});
        }
        // right
        if (!dist[r1][c1][r2][c2][(d1+1)%4]) {
            dist[r1][c1][r2][c2][(d1+1)%4] = dist[r1][c1][r2][c2][d1] + 1;
            q.push({r1,c1,r2,c2,(d1+1)%4});
        }

        int nr1 = r1 + dirs[d1].first;
        int nc1 = c1 + dirs[d1].second;
        int nr2 = r2 + dirs[d2].first;
        int nc2 = c2 + dirs[d2].second;

        if (nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= n || grid[nr1][nc1] || (r1 == 0 && c1 == n - 1)) {
            nr1 = r1;
            nc1 = c1;
        }
        if (nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= n || grid[nr2][nc2] || (r2 == 0 && c2 == n - 1)) {
            nr2 = r2;
            nc2 = c2;
        }
        
        // cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << d1 << " -> " << nr1 << " " << nc1 << " " << nr2 << " " << nc2 << " " << endl;

        if (!dist[nr1][nc1][nr2][nc2][d1]) {
            dist[nr1][nc1][nr2][nc2][d1] = dist[r1][c1][r2][c2][d1] + 1;
            q.push({nr1, nc1, nr2, nc2, d1}); 
        }
    }

    assert(false);
}