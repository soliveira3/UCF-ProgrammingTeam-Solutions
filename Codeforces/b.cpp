#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;


void printPref(vector<vector<int>> &pref, int n) {
    cout << '\n';
    rep (i, 0, n) {
        rep (j, 0, n) {
            cout << pref[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void dfs(int x, int y, int n, vector<string> &grid, vector<vector<bool>> &vis) {
    if (vis[x][y]) return;
    vis[x][y] = true;

    if (x && grid[x-1][y] == '#') dfs(x-1, y, n, grid, vis);
    if (x < n-1 && grid[x+1][y] == '#') dfs(x+1, y, n, grid, vis);
    if (y && grid[x][y-1] == '#') dfs(x, y-1, n, grid, vis);
    if (y < n-1 && grid[x][y+1] == '#') dfs(x, y+1, n, grid, vis);
}


pair<bool, pll> checkStatus(vector<string> grid, int n) {
    pll startGuy = {-1ll, -1ll};

    vector<vector<int>> pref(n, vector<int>(n, 0));
    bool possible = true;
    rep (i, 0, n) rep (j, 0, n) {
        if (grid[i][j] == '#') {
            pref[i][j] = 1;
            startGuy = {i, j};
        } else pref[i][j] = 0;

        if (j && grid[i][j] == '#') pref[i][j] += pref[i][j-1];
        if (pref[i][j] > 2) possible = false;
    }

    // printPref(pref, n);


    pref.assign(n, vector<int>(n, 0));
    rep (i, 0, n) rep (j, 0, n) {
        if (grid[i][j] == '#') pref[i][j] = 1;
        else pref[i][j] = 0;

        if (i && grid[i][j] == '#') pref[i][j] += pref[i-1][j];
        if (pref[i][j] > 2) possible = false;
    }

    // printPref(pref, n);

    return {possible, startGuy};
}


bool isConnected(vector<string> &grid, int n, pll startGuy) {
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    dfs(startGuy.first, startGuy.second, n, grid, vis);
    bool connected = true;
    rep (i, 0, n) {
        rep (j, 0, n) {
            if (!vis[i][j] && grid[i][j] == '#') {
                connected = false;
            }
        }
    }

    return connected;
}


void solve()
{
    ll n;
    cin >> n;


    pll startGuy = {-1ll, -1ll};
    vector<string> grid(n), newGrid;
    rep (i, 0, n) cin >> grid[i];

    // BASE CASE
    if (n <= 2) {
        cout << "YES\n";
        return;
    }

    pair<bool, pll> res = checkStatus(grid, n);
    bool possible = res.first;
    startGuy = res.second;

    // BASE CASE
    if (!possible) {
        cout << "NO\n";
        return;
    }

    // NO BLACK GUYS
    if (startGuy == (pll){-1ll, -1ll}) {
        cout << "YES\n";
        return;
    }

    // FULLY CONNECTED
    if (isConnected(grid, n, startGuy)) {
        cout << "YES\n";
        return;
    }


    // Try up left up left
    newGrid = grid;
    ll pi = startGuy.first, pj = startGuy.second;
    bool goUp = true;
    while (pi >= 0 && pj >= 0) {
        newGrid[pi][pj] = '#';
        if (goUp) pi--;
        else pj--;
        goUp = !goUp;
    }

    if (checkStatus(newGrid, n).first && isConnected(newGrid, n, startGuy)) {
        cout << "YES\n";
        return;
    }

    // try left up left up
    newGrid = grid;
    pi = startGuy.first, pj = startGuy.second;
    goUp = false;
    while (pi >= 0 && pj >= 0) {
        newGrid[pi][pj] = '#';
        if (goUp) pi--;
        else pj--;
        goUp = !goUp;
    }

    if (checkStatus(newGrid, n).first && isConnected(newGrid, n, startGuy)) {
        cout << "YES\n";
        return;
    }

    // Try up right
    newGrid = grid;
    pi = startGuy.first, pj = startGuy.second;
    goUp = true;
    while (pi >= 0 && pj < n) {
        newGrid[pi][pj] = '#';
        if (goUp) pi--;
        else pj++;
        goUp = !goUp;
    }

    if (checkStatus(newGrid, n).first && isConnected(newGrid, n, startGuy)) {
        cout << "YES\n";
        return;
    }

    // try right up
    newGrid = grid;
    pi = startGuy.first, pj = startGuy.second;
    goUp = false;
    while (pi >= 0 && pj < n) {
        newGrid[pi][pj] = '#';
        if (goUp) pi--;
        else pj++;
        goUp = !goUp;
    }

    if (checkStatus(newGrid, n).first && isConnected(newGrid, n, startGuy)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}



int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc; cin >> tc;
    while (tc--) solve();
}