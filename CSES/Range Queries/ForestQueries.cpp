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
 
    vector<string> forest(n);
    for (auto &s : forest) cin >> s;
 
    vector<vector<ll>> pref(n+1, vector<ll> (n+1, 0));
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] = ((forest[i-1][j-1] == '*') ? 1 : 0) + pref[i][j-1];
 
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] += pref[i-1][j];
 
 
    while (m--)
    {
        ll x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
 
        cout << pref[y2][x2] - pref[y2][x1-1] - pref[y1-1][x2] + pref[y1-1][x1-1] << endl;
    }
 
    return 0;
}