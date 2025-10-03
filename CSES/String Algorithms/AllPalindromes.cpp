#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
 
array<vll, 2> manacher(const string& s)
{
	ll n = sz(s);
	array<vll,2> p = {vll(n+1), vll(n)};
	rep(z,0,2) for (ll i=0,l=0,r=0; i < n; i++)
    {
		ll t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		ll L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    string s; cin >> s;
 
    array<vll, 2> ans = manacher(s);
    vll mx(sz(s), 1);
 
    // Evens, odds, backtrack
    rep (i, 0, sz(ans[0])) mx[i+ans[0][i]-1] = max(mx[i+ans[0][i]-1], 2*ans[0][i]);
    rep (i, 0, sz(ans[1])) mx[i+ans[1][i]] = max(mx[i+ans[1][i]], 2*ans[1][i]+1);
    for (int i = sz(mx)-1; i >= 1; i--) mx[i-1] = max(mx[i-1], mx[i]-2);
 
    rep (i, 0, sz(mx)) cout << mx[i] << " ";
    cout << '\n';
}