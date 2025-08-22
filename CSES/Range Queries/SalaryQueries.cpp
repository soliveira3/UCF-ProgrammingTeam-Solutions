#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
struct Tree
{
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; }
    vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
 
    void update(int pos, T val)
    {
		for (s[pos += n] += val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
 
    T query(int b, int e)
    {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, q;
    cin >> n >> q;
 
    vll salary(n), values;
 
    rep (i, 0, n)
    {
        cin >> salary[i];
        values.push_back(salary[i]);
    }
 
    vector<tuple<char, int, int>> queries(q);
 
    char op;
    int a, b;
    rep (i, 0, q)
    {
        cin >> op >> a >> b;
        queries[i] = tie(op, a, b);
        if (op == '!') values.push_back(b);
    }
 
    sort(all(values));
    values.erase(unique(all(values)), values.end());
 
    Tree st(sz(values));
 
    rep (i, 0, n)
    {
        ll x = lower_bound(all(values), salary[i]) - values.begin();
        st.update(x, 1);
    }
 
    rep (i, 0, q)
    {
        tie(op, a, b) = queries[i];
 
        if (op == '!')
        {
            // Unsetting
            ll i = lower_bound(all(values), salary[a-1]) - values.begin();
            st.update(i, -1);
            salary[a-1] = b;
 
            // Setting
            i = lower_bound(all(values), salary[a-1]) - values.begin();
            st.update(i, 1);
        }
 
        else
        {
            ll l = lower_bound(all(values), a) - values.begin();
            ll r = upper_bound(all(values), b) - values.begin();
            cout << st.query(l, r) << '\n';
        }
    }
}