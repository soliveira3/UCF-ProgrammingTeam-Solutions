#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
 
vll Z(const string& S)
{
	vll z(sz(S));
	int l = -1, r = -1;
 
    rep(i,1,sz(S))
    {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}
 
    return z;
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    string s; cin >> s;
 
    vll z = Z(s), ans;
    ll n = sz(z);
    z.push_back(0);
 
    rep (i, 0, n)
        if (i+z[i+1]+1 >= n)
            cout << i+1 << ' ';
 
    cout << '\n';
}