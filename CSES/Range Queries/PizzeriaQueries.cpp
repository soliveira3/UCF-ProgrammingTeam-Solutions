#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
 
struct node
{
    pll val = {LLONG_MAX, LLONG_MAX};
    ll lo, hi, mid;
    node *left = nullptr, *right = nullptr;
 
    node (ll l, ll h) : lo(l), hi(h)
    {
        mid = (lo + hi) / 2;
        if (lo + 1 == hi) return;
        left = new node(lo, mid);
        right = new node(mid, hi);
    }
 
    void merge()
    {
        val = min(left->val, right->val);
    }
 
    void set(ll i, ll x)
    {
        if (lo + 1 == hi)
        {
            val = {x, i};
            return;
        }
 
        if (i < mid) left->set(i, x);
        else right->set(i, x);
        merge();
    }
 
    pll query(ll l, ll r)
    {
        if (r <= lo || l >= hi) return { LLONG_MAX, LLONG_MAX };
        if (lo >= l && hi <= r) return val;
        return min(left->query(l, r), right->query(l, r));
    }
};
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, q;
    cin >> n >> q;
 
    vector<ll> a(n);
    rep (i, 0, n) cin >> a[i];
 
    node leftSt(0, n), rightSt(0, n);
 
    rep (i, 0, n) leftSt.set(i, a[i]+i);
    rep (i, 0, n) rightSt.set(i, a[i] + (n-1-i));
 
 
    ll op, x, k;
    while (q--)
    {
        cin >> op >> k;
        k--;
 
        if (op == 1)
        {
            cin >> x;
            leftSt.set(k, x+k);
            rightSt.set(k, x+(n-k-1));
        }
 
        else
        {
            pll lq = leftSt.query(k, n);
            pll rq = rightSt.query(0, k+1);
 
            lq.first -= lq.second;
            lq.first += (lq.second - k);
            rq.first -= n-rq.second-1;
            rq.first += (k - rq.second);
            cout << min(lq.first, rq.first) << '\n';
        }
    }
}