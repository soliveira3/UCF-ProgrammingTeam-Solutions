#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
typedef struct segTree
{
    ll size;
    vector<ll> values;
 
    ll NEUTRAL_ELEMENT = INT_MIN;
 
    void init(ll n)
    {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2 * size, 0);
    }
 
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1) {
            if (lx < (ll)a.size()) values[x] = a[lx];
            return;
        }
 
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
 
        values[x] = max(values[2 * x + 1], values[2 * x + 2]);
    }
 
    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }
 
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1) {
            values[x] = v;
            return;
        }
 
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
 
        values[x] = max(values[2 * x + 1], values[2 * x + 2]);
    }
 
    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }
 
    int first_above(int v, int x, int lx, int rx)
    {
        if (values[x] < v) return -1;
        if (rx - lx == 1)
        {
            set(lx, values[x] - v);
            return lx;
        }
 
        int m = (lx + rx) / 2;
 
        int res = first_above(v, 2*x + 1, lx, m);
        if (res == -1) res = first_above(v, 2*x + 2, m, rx);
 
        return res;
    }
 
    int first_above(int v) {
        return first_above(v, 0, 0, size);
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
 
    while (m--)
    {
        cin >> n;
        cout << st.first_above(n) + 1 << ' ';
    }
 
    cout << endl;
    return 0;
}