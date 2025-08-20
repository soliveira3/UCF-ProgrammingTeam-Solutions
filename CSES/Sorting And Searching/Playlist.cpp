#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll n; cin >> n;
    vll a(n);
    map<ll, ll> freq;
    ll leftPointer = 0, ans = 1;
 
    rep (i, 0, n)
    {
        cin >> a[i];
 
        if (freq.find(a[i]) == freq.end())
            freq.emplace(a[i], 1);
        else
        {
            freq.at(a[i])++;
            while (freq.at(a[i]) > 1)
                freq.at(a[leftPointer++])--;
        }
 
        ans = max(ans, i-leftPointer+1);
    }
 
    cout << ans << '\n';
 
    return 0;
}