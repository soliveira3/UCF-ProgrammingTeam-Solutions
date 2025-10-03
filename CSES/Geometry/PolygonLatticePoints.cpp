#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
ll cross(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first*b.second - a.second*b.first;
}
 
ll polygonArea(vector<pair<ll, ll>> &v)
{
    ll a = cross(v.back(), v[0]);
    rep (i, 0, sz(v)-1) a += cross(v[i], v[i+1]);
    return a;
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pts(n);
    for (pair<ll, ll> &p : pts) cin >> p.first >> p.second;
 
    ll b = 0;
    ll area = abs(polygonArea(pts)/2);
    area += 1;
 
    rep (i, 0, n)
    {
        ll dx = abs(pts[(i+1)%n].first - pts[i].first);
        ll dy = abs(pts[(i+1)%n].second - pts[i].second);
        b += gcd(dx, dy);
    }
 
    ll a = area - (b/2);
    cout << a << " " << b << "\n";
}

