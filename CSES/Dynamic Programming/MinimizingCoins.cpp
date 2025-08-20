#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<ll> dp(10e6+5, -1);
vector<ll> a;
ll INF = 10e13;
 
ll calc(ll n)
{
    if (n == 0) return 0;
    if (n < 0) return INF;
    if (dp[n] != -1) return dp[n];
 
    ll currentBest = INF;
    for (int i = 0; i < a.size(); i++)
        currentBest = min(currentBest, calc(n-a[i]) + 1);
 
    return dp[n] = currentBest;
}
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n, x;
    cin >> n >> x;
 
    a.assign(n, 0);
    for (auto &i : a) cin >> i;
 
    calc(x);
    cout << ((dp[x] >= INF) ? -1 : dp[x]) << '\n';
 
    return 0;
}