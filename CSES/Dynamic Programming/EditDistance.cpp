#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
int main ()
{
    string a, b;
    cin >> a >> b;
 
    vector<vll> dp(a.size()+1, vll (b.size()+1, 0));
 
    // Initialization States
    rep(i, 0, a.size()+1) dp[i][0] = i;
    rep(j, 0, b.size()+1) dp[0][j] = j;
 
    rep (i, 0, a.size())
    {
        rep (j, 0, b.size())
        {
            dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + 1;
 
            if (a[i] == b[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
        }
    }
 
    cout << dp[a.size()][b.size()] << '\n';
 
    return 0;
}