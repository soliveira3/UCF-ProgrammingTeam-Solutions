#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
struct it{
    ll pref, suf, maximum, sum;
};
 
struct Tree
{
    typedef it T;
    static constexpr T unit = {0, 0, 0, 0};
 
    T f(T a, T b) {
        return {
            max(a.pref, a.sum + b.pref),
            max(b.suf, a.suf + b.sum),
            max(max(a.maximum, b.maximum), a.suf + b.pref),
            a.sum + b.sum
        };
    }
 
    vector<T> s;
 
    int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
 
    void update(int pos, T val)
    {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
 
    T query(int b, int e)
    {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2)
        {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
 
        return f(ra, rb);
    }
};
 
int main()
{
    ll n, m;
    cin >> n >> m;
 
    vll a(n);
    Tree st(n);
    rep (i, 0, n)
    {
        ll x; cin >> x;
        it y = ((x > 0) ? (it){x, x, x, x} : (it){0, 0, 0, x});
        st.update(i, y);
    }
 
 
 
    while (m--)
    {
        ll k, x;
        cin >> k >> x;
        k--;
 
        it y = ((x > 0) ? (it){x, x, x, x} : (it){0, 0, 0, x});
        st.update(k, y);
 
        cout << st.query(0, n).maximum << '\n';
    }
}

