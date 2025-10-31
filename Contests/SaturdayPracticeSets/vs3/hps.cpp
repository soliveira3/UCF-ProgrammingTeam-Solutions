#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

map<char, int> mp = {{'H', 0}, {'P', 1},{'S', 2}};

ll n;
string s;

// char, k, pos
ll dp[5][25][100005];

ll go(char c, ll k, ll pos)
{
    if (pos == n) return 0;
    if (dp[mp[c]][k][pos] != -1) return dp[mp[c]][k][pos];

    ll ans = 0;
    if (k == 0) {
        ans = (s[pos] == c) + go(c, 0, pos+1);
    }

    else {
        ans = max(ans, (s[pos] == c) + go('H', k-(c != 'H'), pos+1));
        ans = max(ans, (s[pos] == c) + go('P', k-(c != 'P'), pos+1));
        ans = max(ans, (s[pos] == c) + go('S', k-(c != 'S'), pos+1));
    }

    return dp[mp[c]][k][pos] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll k;
    cin >> n >> k; 
    memset(dp, -1, sizeof(dp));

    s.assign(n, ' ');
    for (int i = 0; i < n; i++) cin >> s[i];


    ll ans = 0;
    ans = max(ans, go('H', k, 0));
    ans = max(ans, go('P', k, 0));
    ans = max(ans, go('S', k, 0));

    cout << ans << '\n';
}