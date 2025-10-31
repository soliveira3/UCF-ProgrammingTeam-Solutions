#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

ll modexp(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b*b % MOD, e/=2)
        if (e & 1) ans = ans * b % MOD;
    return ans;
}

vector<ll> solveOne(int N) {
    vector<ll> res(32);
    if (N == 0) return res; 
    int i = 31;
    while (!(N & (1 << i))) i--;

    int M = 0;
    for (; i >= 0; i--) {
        res[i] += M / 2;
        if (N & (1 << i)) {
            M += 1 << i;
            res[i] += N - M + 1;
        }
    }
    return res;
}

vector<ll> solve() {
    int l, r; cin >> l >> r;
    auto prob = solveOne(r);
    auto tmp = solveOne(l-1);
    for (int i = 0; i < 32; i++) prob[i] = prob[i] - tmp[i] % MOD;
    for (int i = 0; i < 32; i++) prob[i] = (prob[i] * modexp(r-l+1, MOD-2) % MOD) % MOD;
    for (int i = 0; i < 32; i++) prob[i] = (1 - prob[i] + MOD) % MOD;


    for (int i = 0; i < 32; i++) {
        cout << i << ": " << prob[i] << "\n";
    }
    return prob;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    auto prob1 = solve();
    auto prob2 = solve();
    auto prob3 = solve();

    ll res = 1;
    for (int i = 0; i < 32; i++) {
        ll a = prob1[i] % MOD, b = prob2[i] % MOD, c = prob3[i] % MOD;
        ll a1 = (1 - a + MOD) % MOD;
        ll b1 = (1 - b + MOD) % MOD;
        ll c1 = (1 - c + MOD) % MOD;
        ll help = ((a * b) % MOD * c) % MOD; 
        help += ((a * b1) % MOD * c1) % MOD;
        help += ((a1 * b1) % MOD * c) % MOD;
        help += ((a1 * b) % MOD * c1) % MOD;
        cout << i << ": " << a << " " << b << " " << c << " " << res << " " << help << " " << "\n";
        cout << i << ": " << a1 << " " << b1 << " " << c1 << " " << help << " " << "\n";
        res *= help;
        res %= MOD; 
    }

    cout << (1 - res + MOD) % MOD << "\n";
}