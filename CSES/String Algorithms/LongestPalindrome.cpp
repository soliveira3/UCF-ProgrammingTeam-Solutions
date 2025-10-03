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
 
    ll evenIndex = max_element(all(ans[0])) - ans[0].begin();
    ll oddIndex = max_element(all(ans[1])) - ans[1].begin();
 
    if (2*ans[0][evenIndex] > 2*ans[1][oddIndex]+1)
        cout << s.substr(evenIndex-ans[0][evenIndex], 2*ans[0][evenIndex]);
    else
        cout << s.substr(oddIndex-ans[1][oddIndex], 2*ans[1][oddIndex]+1);
 
    cout << '\n';
}