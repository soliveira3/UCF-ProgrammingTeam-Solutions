#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (int)b; ++i)
typedef long long ll;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n = 9;
    vector<vll> grid(9, vll(9, 0));
    vector<vector<vector<bool>>> canBe(9, vector<vector<bool>>(9, vector<bool>(9, 1)));

    rep (i, 0, 9) rep (j, 0, 9) {
        cin >> grid[i][j];
        grid[i][j]--;
  
        // updating can be
        if (grid[i][j] != -1)
            rep (k, 0, 9) canBe[i][j][k] = (k == grid[i][j]);
    }


    bool modified = true;
    while (modified) {

        modified = false;

        // updating canBe
        rep (i, 0, n) rep (j, 0, n) {
            if (grid[i][j] != -1) continue;
            vector<bool> h(9, 1), v(9, 1), s(9, 1);
            
            // going through the row
            rep (x, 0, n) if (grid[i][x] != -1) h[grid[i][x]] = false;
            // going through the col
            rep (x, 0, n) if (grid[x][j] != -1) v[grid[x][j]] = false;
            
            // going through the square
            ll oi = i - (i%3), oj = j - (j%3);
            rep (x, oi, oi+3) rep (y, oj, oj+3) {
                if (grid[x][y] != -1)
                    s[grid[x][y]] = false;
            }

            rep (k, 0, n)
                canBe[i][j][k] = (h[k] & v[k] & s[k]);
        }
        

        // doing rules
        rep (i, 0, n) rep (j, 0, n) {
            if (grid[i][j] != -1) continue;

            int numCanBe = 0, changeTo = -1;
            rep (k, 0, n) {
                if (canBe[i][j][k]) {
                    numCanBe++;
                    changeTo = k;
                }
            }

            // rule 1
            if (numCanBe == 1) {
                grid[i][j] = changeTo;
                modified = true;
                continue;
            }


            // rule 2
            vector<bool> h(9, false), v(9, false), s(9, false);
            rep (x, 0, n) {
                if (x != j)
                    rep (k, 0, n) h[k] = (h[k] | canBe[i][x][k]);
            }
    
            // going through the col
            rep (x, 0, n) {
                if (x != i)
                    rep (k, 0, n) v[k] = (v[k] | canBe[x][j][k]);
            }

            // going through the square
            ll oi = i - (i%3), oj = j - (j%3);
            rep (x, oi, oi+3) rep (y, oj, oj+3) {
                if (x != i || y != j)
                    rep (k, 0, n) s[k] = (s[k] | canBe[x][y][k]);
            }

            rep (k, 0, n) {
                if (canBe[i][j][k] && !h[k] || canBe[i][j][k] && !v[k] || canBe[i][j][k] && !s[k])
                    grid[i][j] = k;
            }

            // updating can be
            if (grid[i][j] != -1) {
                rep (k, 0, 9) canBe[i][j][k] = (k == grid[i][j]);
                modified = true;
            }
        }
    }

    bool good = true;
    rep (i, 0, n) rep (j, 0, n) {
        if (grid[i][j] == -1) good = false;
    }

    cout << ((good) ? "Easy\n" : "Not easy\n");
    rep (i, 0, n) 
    {
        rep (j, 0, n) {
           if (grid[i][j] == -1) cout << ". ";
           else cout << grid[i][j]+1 << " ";
        }
        cout << '\n';
    }
}
