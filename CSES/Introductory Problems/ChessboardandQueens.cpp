#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
typedef long long ll;
typedef pair<int, int> pll;
typedef vector<int> vll;
 
 
ll place(int cur, int rowNum, vector<bool> col, vector<bool> up, vector<bool> down, vector<string> &grid)
{
    if (cur == 8) return 1;
 
    ll ans = 0;
    rep (i, 0, 8)
    {
        int ud = rowNum + i, dd = rowNum-i +7;
        if (!col[i] && !up[ud] && !down[dd] && grid[rowNum][i] != '*')
        {
            col[i] = true;
            up[ud] = true;
            down[dd] = true;
            ans += place(cur+1, rowNum+1, col, up, down, grid);
            col[i] = false;
            up[ud] = false;
            down[dd] = false;
        }
    }
 
    return ans;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    vector<string> grid(8);
    rep (i, 0, 8) cin >> grid[i];
 
    vector<bool> col(8, false), up(15, false), down(15, false);\
    cout << place(0, 0, col, up, down, grid) << '\n';
}