#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;


int main () {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    vector<ld> a(n);
    vector<ld> prefx2(n, 0), prefx(n, 0);
    rep (i, 0, n) cin >> a[i];
        
    sort(a.begin(), a.end());
    
    rep (i, 0, n) {
        prefx2[i] += a[i]*a[i];
        prefx[i] += a[i];
        
        if (i > 0) {
            prefx2[i] += prefx2[i-1];
            prefx[i] += prefx[i-1];
        }
    }
    
    cout << fixed << setprecision(12);

    // rep (i, 0, n) cout << prefx2[i] << " ";
    // cout << '\n';
    
    ld mn = 1e18;
    rep (i, k-1, n) {
        ld sum = prefx[i] - (i-k >= 0 ? prefx[i-k] : 0);
        ld mean = sum / (ld)k;

        ld X2 = prefx2[i] - (i-k >= 0 ? prefx2[i-k] : 0);
        ld ans = abs(X2 - (2*mean*sum) + (k*(mean*mean)));
        // cout << X2 << " " << 2*mean*sum << " " << k*mean*mean << '\n';
        mn = min(mn, ans);
        // cout << ans << '\n';
    }

    cout << mn << '\n';
}