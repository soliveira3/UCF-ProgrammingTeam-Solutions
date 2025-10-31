#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    g = vector<vector<int>>(n*5+5, vector<int>(m*5+5));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char p;
            cin >> p;
            g[n*2+i][m*2+j] = (p == '#');
        }
    }

    for(int i = 0; i < 5*n; i++) {
        for(int j = 0; j < 5*m; j++) {
            g[i][j] = g[2*n+(i%n)][2*m+(j%m)];
        }
    }

    vector<vector<int>> possible(n*5+5, vector<int>(m*5+5));
    queue<array<int,2>> q;
    q.push({n*2, m*2});
    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,-1,1};

    while(!q.empty()) {
        auto [r,c] = q.front(); q.pop();
        if(possible[r][c]) continue;
        possible[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr < 0 || nc < 0 || nr >= 5*n || nc >= 5*m || g[nr][nc] == 1)continue;
            q.push({nr,nc}); 
        }
    }

    // for(int i = 0; i < 5*n; i++) {
    //     for(int j = 0; j < 5*m; j++) {
    //         cout << possible[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++) {
        int r,c;
        cin >> r >> c;
        if(r <= (-2) * n || c <= (-2) * m || r > 3 * n || c > 3 * m) {
            int R = ((r % n) + n) % n;
            int C = ((c % m) + m) % m;
            if (r <= -2 * n) R -= 2 * n;
            if (r >= 3 * n) R += 3 * n;
            if (c < -2 * m) C -= 2 * m;
            if (c >= 3 * m) C += 3 * m;
            // cout << r << " " << c << " " << R << " " << C << "!\n";

            cout << (possible[R+2*n][C+2*m] ? "yes" : "no") << "\n";
        } else {
            // cout << "CHECKING " << r << " " << c << '\n';
            // int R = ((r % n) + n) % n;
            // int C = ((c % m) + m) % m;
            // if (r <= -1 * n) R -= 1 * n;
            // if (r >= 2 * m) R += 2 * n;
            // if (c < -1 * m) C -= 1 * m;
            // if (c >= 2 * m) C += 2 * m;
            // cout << r << " " << c << " " << R << " " << C << "!!!!\n";

            if(possible[r+2*n][c+2*m]) cout << "yes\n";
            else cout << "no\n";
        } 
    }

}