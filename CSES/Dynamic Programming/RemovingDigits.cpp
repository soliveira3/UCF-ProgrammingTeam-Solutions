#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<ll> dp(1e7+5, -1);
 
 
ll solution(ll n)
{
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
 
 
    ll modN = n;
    ll newVal = LLONG_MAX;
 
    while (modN > 0)
    {
        ll digit = modN % 10;
        modN /= 10;
 
        if (digit == 0) continue;
 
        newVal = min(newVal, solution(n-digit)+1);
    }
 
    return dp[n] = newVal;
}
 
 
int main ()
{
    ll n; cin >> n;
    cout << solution(n) << '\n';
 
	return 0;
}