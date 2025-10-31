#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;



ll findPos(ll add, ll sz, ll x, ll y, ll layer)
{
    if (sz == 1) return layer+1;

    // cout << layer << '\n';

    ll flipX = (sz/2)-1 - (x - (sz/2)), flipY = (sz/2)-1 - (y - (sz/2));

    // top left
    if (x < (sz/2) && y < (sz/2)) 
        return findPos(add*4, sz/2, x, y, layer);

    // top right
    if (x < (sz/2) && y >= (sz/2)) 
        return findPos(add*4, sz/2, x, flipY, add*3 + (add-layer-1));
    
    // bottom left
    if (x >= (sz/2) && y < (sz/2)) 
        return findPos(add*4, sz/2, flipX, y, add + (add-layer-1));

    // bottom right
    if (x >= (sz/2) && y >= (sz/2)) 
        return findPos(add*4, sz/2, flipX, flipY, add*2+layer);

    return 0;
}


pll findNum(ll sz, ll height, ll x, ll y, ll n)
{
    // cout << height << " " << x << " " << y << " " << n << " " << sz << '\n';
    if (height == 1) return {x,y};

    ll fourth = height/4;
    
    if (n > 3*fourth)
    {
        x = 2*sz - x - 1;
        // y = 2*sz - y - 1;
        ll np = (height-n+1);
        // ll np = 3*(height/4) + ((height/4)-(n-(height/4))-1);
        pll res = findNum(sz*2, height/4, x, y, np);
        return res;
    }

    else if (n > 2*fourth)
    {
        x = 2*sz - x - 1;
        y = 2*sz - y - 1;
        ll np = height/2 - (height-n+1) + 1;
        pll res = findNum(sz*2, height/4, x, y, np);
        return res;
    }

    else if (n > fourth)
    {
        y = 2*sz - y - 1;
        ll np = height / 2 - n + 1;
        // ll np = (height/4) + ((height/4)-(n-(height/4))-1);
        pll res = findNum(sz*2, height/4, x, y, np);
        return res;
    }

    return findNum(sz*2, height/4, x,y,n);    
}



signed main ()
{
    cin.tie(0)->sync_with_stdio(0);
    ll q, op, k, n;
    cin >> q;

    while (q--)
    {
        cin >> op >> k >> n;
        n--;

        if (op == 1)
        {
            ll x = n / (1ll << k);
            ll y = n - (x * (1ll << k));
            
            cout << findPos(1, (1LL << k), x, y, 0) << '\n';
        }

        else 
        {
            pll res = findNum(1, (1ll << k) * (1ll << k), 0, 0, n+1);
            ll ans = 0;

            // cout << res.first << " " << res.second << '\n';

            ans = (res.second*(1ll << k)) + res.first + 1;
            cout << ans << '\n';
        }
    }


    // pll res = findNum(1, (1ll << 3) * (1ll << 3), 0, 0, n+1);

    return 0;
}