#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (int)b; i++)
#define sz(x) (x).size()
typedef long long ll;
typedef vector<ll> vll;


int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    cout << "1 1 " << (m-((n-1)*2))-1 << " " << (m-((n-1)*2)) << '\n';

    ll totalLeft = m-1;
    ll catagoriesLeft = n-1;
    rep (i, 0, n-1)
    {
        ll denom = (totalLeft/catagoriesLeft);
        ll num = denom/2 + 1;
        totalLeft -= denom;
        catagoriesLeft--;
    
        cout << num << " " << denom << " 1 2\n";
    }
}