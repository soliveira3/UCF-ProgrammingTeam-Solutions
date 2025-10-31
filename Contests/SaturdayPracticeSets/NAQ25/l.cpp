#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef vector<ll> vll;


int main () {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    vll a(n);
    rep (i, 0, n) cin >> a[i];

    int big = a.back();
    big /= 3;
    int small = a[0];
    small /= 3;

    cout << small << " " << (a[1] - (2*small)) << " " << big << '\n';
}