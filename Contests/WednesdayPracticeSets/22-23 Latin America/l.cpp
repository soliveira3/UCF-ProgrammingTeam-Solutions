#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x).size()

string s;
int D;

void go(int pos, vector<int> &dp)
{
    if (pos == sz(s)-1) return;

    vector<int> z(sz(s));
    int l = -1, r = -1, count = 0;
    rep (i, pos+1, sz(s))
    {
        z[i] = i >= r ? 0 : min(r-i, z[i-1]);
        while (i + z[i] < sz(s) && s[i+z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i+z[i];

        if (i >= pos+D && z[i-1]+1 != z[i] && dp[pos]+1 < dp[i])
        {
            dp[i] = dp[pos]+1;
            go(i, dp);
            break;
        }
        
        if (dp[pos]+1 < dp[i])
        {
            dp[i] = dp[pos];
            go(i, dp);
        }
    }
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> D;

    if (sz(s) == 1 || D >= sz(s)){
        cout << 1 << '\n';
        return 0;
    }

    vector<int> dp(sz(s), 1e9);
    dp[0] = 1;

    
    go(0, dp);
    
    cout << '\n';
    rep (i, 0, sz(s)) cout << dp[i] << ' ';
    cout << '\n';

    cout << dp[sz(s)-1] << '\n';
}