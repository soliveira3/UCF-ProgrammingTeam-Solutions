#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
typedef struct item {
    ll seg, pref, suf, sum;
} item;
 
 
typedef struct segTree
{
    ll size;
    vector<item> values;
 
    item single(ll v) {
        if (v > 0) return {v, v, v, v};
        return {0, 0, 0, v};
    }
 
    void init(ll n)
    {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2*size, single(0));
    }
 
    item merge(item a, item b)
    {
        return
        {
            max(max(a.seg, b.seg), a.suf+b.pref),
            max(a.pref, a.sum+b.pref),
            max(b.suf, b.sum+a.suf),
            a.sum+b.sum
        };
    }
 
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1) {
            if (lx < (ll)a.size()) values[x] = single(a[lx]);
            return;
        }
 
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
 
        values[x] = merge(values[2*x + 1], values[2*x + 2]);
    }
 
    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }
 
 
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1) {
            values[x] = single(v);
            return;
        }
 
        ll m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
 
        values[x] = merge(values[2*x + 1], values[2*x + 2]);
    }
 
    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }
 
 
    item calc(ll l, ll r) {
        return calc(l, r, 0, 0, size);
    }
 
    item calc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx) return {0, 0, 0, 0};
        if (lx >= l && rx <= r) return values[x];
 
        ll m = (lx + rx) / 2;
        item s1 = calc(l, r, 2 * x + 1, lx, m);
        item s2 = calc(l, r, 2 * x + 2, m, rx);
 
        return merge(s1, s2);
    }
 
} segTree;
 
 
 
int main()
{
    ios::sync_with_stdio(false);
 
    ll n, m;
    cin >> n >> m;
 
    segTree st;
    st.init(n);
 
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    st.build(a);
 
 
    // Queries
    while (m--)
    {
        ll op;
        cin >> op;
 
        if (op == 1)
        {
            ll k, u;
            cin >> k >> u;
            k--;
 
            st.set(k, u);
        }
 
        else
        {
            ll a, b;
            cin >> a >> b;
            a--;
 
            item x = st.calc(a, b);
            cout << x.pref << '\n';
        }
    }
 
    cout << endl;
    return 0;
}