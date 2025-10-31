#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> extra(n+2);
    vector<ll> solves(n+2);
    for(int j = 1; j <= n; j++) {
        cin >> extra[j];
    }
    for(int i = 0; i < n; i++) {
        cin >> solves[i];
    }


    ld res = 0;
    for(int mask = 0; mask < (1<<10); mask++){
        ll bits = __builtin_popcountll(mask);
        ld cur = extra[bits];
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) cur += solves[i];
        }
        res = max(res, cur/(ld)(bits));
    }

    cout << fixed << setprecision(6);
    cout << res << '\n';
}