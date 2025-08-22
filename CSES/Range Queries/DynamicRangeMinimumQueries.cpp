#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
typedef struct segTree
{
    ll size;
    vector<ll> values;
 
    void init (ll n)
    {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2*size, 0LL);
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
 
        values[x] = min(values[2*x + 1], values[2*x + 2]);
    }
 
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }
 
    void set (ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            values[x] = v;
            return;
        }
 
        int m = (lx + rx) / 2;
 
        if (i < m)
            set(i, v, 2*x + 1, lx, m);
        else
            set(i, v, 2*x + 2, m, rx);
 
        values[x] = min(values[2*x + 1], values[2*x + 2]);
    }
 
    void set (ll i, ll v)
    {
        set(i, v, 0, 0, size);
    }
 
 
    ll calc (ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx) return LONG_LONG_MAX;
        if (lx >= l && rx <= r) return values[x];
 
        ll m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2*x + 1, lx, m);
        ll s2 = calc(l, r, 2*x + 2, m, rx);
 
        return min(s1, s2);
    }
 
    ll calc (ll l, ll r)
    {
        return calc(l, r, 0, 0, size);
    }
 
} segTree;
 
int main ()
{
 
    ios::sync_with_stdio(false);
 
    ll n, q;
    cin >> n >> q;
 
    segTree st;
    st.init(n);
 
    vector<ll> a(n);
 
    for (int i = 0; i < n; i++) cin >> a[i];
    st.build(a);
 
    while (q--)
    {
        int op; cin >> op;
 
        if (op == 2)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << st.calc(l, r) << '\n';
        }
 
        else
        {
            ll i, v;
            cin >> i >> v;
            i--;
            st.set(i, v);
        }
    }
 
	return 0;
}