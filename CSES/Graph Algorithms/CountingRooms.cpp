#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
ll n, m;
 
void fill(vector<string> &grid, ll i, ll j)
{
    if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == '#') return;
    grid[i][j] = '#';
 
    fill(grid, i+1, j);
    fill(grid, i-1, j);
    fill(grid, i, j+1);
    fill(grid, i, j-1);
}
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;
    ll count = 0;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
            {
                count++;
                fill(grid, i, j);
            }
 
    cout << count << '\n';
 
    return 0;
}