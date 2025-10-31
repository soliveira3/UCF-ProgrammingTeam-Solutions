#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define sz(x) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<ll> vll;

const ll mod = 1e9+7;
ll spaces, blocks;
vector<vll> dp;


ll go(ll num, ll suffixSize)
{
    if ((num > 0 && suffixSize <= 0) || num < 0) return 0;
    if (num == 0) return dp[num][suffixSize] = 1;
    if (dp[num][suffixSize] != -1) return dp[num][suffixSize]; 

    ll ans = 0;
    rep (stackSize, 0, num+1) {
        ll nextSize = num - (suffixSize*stackSize);
        ans = (ans + go(nextSize, min(suffixSize-1, nextSize))) % mod;
    }

    return dp[num][suffixSize] = ans;
}


int main(){

    cin >> spaces >> blocks;

    blocks -= spaces;

    dp.assign(blocks+1, vll(spaces+1, -1));
    rep (i, 0, spaces+1) dp[0][i] = 1;
    rep (i, 0, blocks+1) dp[i][0] = 0;
    dp[0][0] = -1;

    rep (i, 1, blocks+1) go(i, spaces);

    ll ans = 0;
    rep (pos, 1 , spaces+1) {
        rep (numBlocks, 1, blocks+1) {
            if (dp[numBlocks][pos] > 0 && dp[blocks-numBlocks][spaces - pos] > 0)
                ans = (ans + (dp[numBlocks][pos] * dp[blocks-numBlocks][spaces - pos])) % mod;
        }
    }

    cout << ans << '\n';

    cout << '\n';

    rep (i, 0, blocks+1) {
        rep (j, 0, spaces+1) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}