#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n; cin >> n;
 
    stack<pll> st;
    st.push({0, 0});
 
    rep (i, 0, n)
    {
        ll x; cin >> x;
 
        while (st.top().first >= x) st.pop();
        cout << st.top().second << ' ';
        st.push({x, i+1});
    }
 
    cout << '\n';
}