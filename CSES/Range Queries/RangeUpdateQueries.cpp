#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
typedef ll item;
 
typedef struct segTree
{
    ll size;
    vector<item> values;
 
    item NEUTRAL_ELEMENT = 0;
 
    item merge (item a, item b) { return a + b; }
 
    item single (ll v) { return v; }
 
    void init(ll n)
    {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2 * size, single(0));
    }
 
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            values[x] += single(v);
            return;
        }
 
        ll m = (lx + rx) / 2;
 
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
 
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
 
    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }
 
    item calc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r) return values[x];
 
        ll m = (lx + rx) / 2;
        item s1 = calc(l, r, 2 * x + 1, lx, m);
        item s2 = calc(l, r, 2 * x + 2, m, rx);
 
        return merge(s1, s2);
    }
 
    item calc(ll l, ll r) {
        return calc(l, r, 0, 0, size);
    }
     
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (ll)a.size())
                values[x] = single(a[lx]);
 
            return;
        }
 
        ll m = (lx + rx) / 2;
 
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
 
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
 
    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }
 
} segTree;
 
int main()
{
    ios::sync_with_stdio(false);
 
    ll n, m;
    cin >> n >> m;
 
    segTree st;
    st.init(n+1);
 
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    while (m--)
    {
        ll op;
        cin >> op;
 
        if (op == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            l--;
 
            st.set(l, v);
            st.set(r, -v);
        }
 
        else
        {
            ll k; cin >> k;
            cout << a[k-1] + st.calc(0, k) << '\n';
        }
    }
 
    return 0;
}