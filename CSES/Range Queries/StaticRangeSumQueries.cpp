#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /*
    YES. I could have used a prefix sum, but simple practive for segTree
 */
 
typedef struct segTree {
 
    ll size;
    vector<ll> values;
    ll NEUTRAL_ELEMENT = 0;
 
    void init (ll n)
    {
        size = 1;
        while (size < n) size *= 2;
        values.resize(2*size);
    }
 
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (ll)a.size())
                values[x] = a[lx];
 
            return;
        }
 
        ll m = (lx + rx) / 2;
 
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
 
        values[x] = values[2*x + 1] + values[2*x + 2];
    }
 
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }
 
    void set (ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            values[x] = x;
            return;
        }
 
        int m = (lx + rx) / 2;
 
        if (i < m)
            set(i, v, 2*x + 1, lx, m);
        else
            set(i, v, 2*x + 2, m, rx);
 
        values[x] = values[2*x + 1] + values[2*x + 2];
    }
 
    void set (ll i, ll v)
    {
        set(i, v, 0, 0, size);
    }
 
 
    ll calc (ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r) return values[x];
 
        ll m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2*x + 1, lx, m);
        ll s2 = calc(l, r, 2*x + 2, m, rx);
 
        return s1 + s2;
    }
 
    ll calc (ll l, ll r)
    {
        return calc(l, r, 0, 0, size);
    }
 
} segTree;
 
int main ()
{
 
    ios::sync_with_stdio(false);
 
    ll n, m;
    cin >> n >> m;
 
    segTree st;
    st.init(n);
 
    vector<ll> a(n);
 
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    st.build(a);
 
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        cout << st.calc(l, r) << '\n';
    }
 
	return 0;
}