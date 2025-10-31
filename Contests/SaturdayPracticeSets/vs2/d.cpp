#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int e = 0, cur = 0;
    rep (i, 0, n)
    {
        cur = ((cur*10) + (s[i] - '0')) % m;
        if (i == n-1 && cur != 0) { cout << "0\n"; return 0; }
        if (cur == 0) e++;
    }

    if (e == 0) { cout << "0\n"; return 0; }
    e--;

    ll ans = 1, b = 2, mod = 1e9+7;
    for (; e; b = b*b % mod, e/=2)
        if (e & 1) ans = ans * b % mod;

    cout << ans << '\n';
}