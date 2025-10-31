#include <bits/stdc++.h>
using namespace std;

int r, c;
int go(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis){
    if (vis[x][y]) return 0;
    vis[x][y] = true;
    int ans = 1;
    if (x > 0 && grid[x-1][y] > grid[x][y]) ans += go(x-1, y, grid, vis);
    if (x < r-1 && grid[x+1][y] > grid[x][y]) ans += go(x+1, y, grid, vis);
    if (y > 0 && grid[x][y-1] > grid[x][y]) ans += go(x, y-1, grid, vis);
    if (y < c-1 && grid[x][y+1] > grid[x][y]) ans += go(x, y+1, grid, vis);

    return ans;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;

    vector<pair<int, int>> pos(r*c+2);

    vector<vector<int>> grid(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
    {
        cin >> grid[i][j];
        pos[grid[i][j]] = {i, j};
    }

    int ans = 1;
    for (int i = 1; i <= r*c; i++)
    {
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        int x = pos[i].first, y = pos[i].second;
        ans = max(ans, go(x, y, grid, vis));
    }

    cout << ans << '\n';
}