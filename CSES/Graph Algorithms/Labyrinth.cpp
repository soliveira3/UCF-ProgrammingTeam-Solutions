#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
 
    ll n, m;
    cin >> n >> m;
 
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;
 
    ll ax, ay, bx, by;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A') { ax = i; ay = j; }
            if (grid[i][j] == 'B') { bx = i; by = j; }
        }
 
 
    queue<pair<ll, ll>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<ll>> distance(n, vector<ll>(m, LONG_LONG_MAX));
 
    visited[ax][ay] = true;
    distance[ax][ay] = 0;
    q.push({ax, ay});
    while (!q.empty())
    {
        pair<ll, ll> pll = q.front(); q.pop();
 
        ll dx[] = {1, -1, 0, 0};
        ll dy[] = {0, 0, 1, -1};
 
        for (int i = 0; i < 4; i++)
        {
            if (pll.first+dx[i] >= n || pll.first+dx[i] < 0 || pll.second+dy[i] >= m || pll.second+dy[i] < 0 || grid[pll.first+dx[i]][pll.second+dy[i]] == '#' || visited[pll.first+dx[i]][pll.second+dy[i]]) continue;
            visited[pll.first+dx[i]][pll.second+dy[i]] = true;
            distance[pll.first+dx[i]][pll.second+dy[i]] = distance[pll.first][pll.second]+1;
            if (grid[pll.first+dx[i]][pll.second+dy[i]] == 'B') break;
            q.push({pll.first+dx[i], pll.second+dy[i]});
        }
    }
 
 
    if (distance[bx][by] == LONG_LONG_MAX) cout << "NO\n";
    else
    {
        cout << "YES" << '\n';
        cout << distance[bx][by] << '\n';
        vector<char> path;
 
        while (distance[bx][by] != 0)
        {
            if (bx > 0 && distance[bx-1][by] == distance[bx][by]-1) { bx--; path.push_back('D'); }
            else if (bx < n-1 && distance[bx+1][by] == distance[bx][by]-1) { bx++; path.push_back('U'); }
            else if (by > 0 && distance[bx][by-1] == distance[bx][by]-1) { by--; path.push_back('R'); }
            else { by++; path.push_back('L'); }
        }
 
        reverse(path.begin(), path.end());
        for (auto c : path) cout << c;
        cout << '\n';
    }
 
	return 0;
}