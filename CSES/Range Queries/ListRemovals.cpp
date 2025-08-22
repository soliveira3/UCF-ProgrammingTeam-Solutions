#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
typedef struct segTree
{
    ll size;
    vector<ll> values;
 
    void init(ll n)
    {
        size = 1;
        while (size < n) size *= 2;
        values.assign(size*2, 0);
    }
 
    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }
 
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            values[x] = v;
            return;
        }
 
        ll m = (lx + rx) / 2;
        if (i < m) set(i, v, x*2+1, lx, m);
        else set(i, v, x*2+2, m, rx);
 
        values[x] = values[x*2+1] + values[x*2+2];
    }
 
    ll find(ll v) {
        return find(v, 0, 0, size);
    }
 
    ll find(ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            set(lx, 0);
            return lx;
        }
 
        ll m = (lx + rx) / 2;
        ll p = values[x*2+1];
 
        if (v < p) return find(v, x*2+1, lx, m);
        else return find(v-p, x*2+2, m, rx);
    }
 
} segTree;
 
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n; cin >> n;
 
    segTree st;
    st.init(n);
    for (int i = 0; i < n; i++) st.set(i, 1);
 
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
 
    while (n--)
    {
        ll x; cin >> x; x--;
        cout << a[st.find(x)] << ' ';
    }
 
    cout << '\n';
    return 0;
}