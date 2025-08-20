#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
void toh(ll n, ll to, ll from, ll tmp)
{
    if (n == 0) return;
 
    toh(n-1, tmp, from, to);
    cout << from << " " << to << "\n";
    toh(n-1, to, tmp, from);
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n; cin >> n;
    cout << ((1 << n)-1) << '\n';
    toh(n, 3, 1, 2);
}