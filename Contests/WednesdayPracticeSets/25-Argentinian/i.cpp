#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;

    vll gold(n+1, 0);

    rep (i, 0, m)
    {
        ll x, y, numSharing = 0;
        cin >> x >> y;

        vll options(n);
        rep (j, 0, n)
        {
            cin >> options[j];
            numSharing += (options[j] == 1);
        }    
        
        if (x/(numSharing+1) >= y) {
            numSharing++;
            gold[n] += x/numSharing;
        } else {
            gold[n] += y;
        }

        rep (j, 0, n)
        {
            if (options[j] == 1) gold[j] += x/numSharing;
            else gold[j] += y; 
        }
    }

    rep (i, 0, n+1) cout << gold[i] << " ";
    cout << '\n';
}