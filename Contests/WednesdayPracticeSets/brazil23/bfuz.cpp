#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

ll modexp(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b*b % mod, e/=2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}


int l1, r1, l2, r2, l3, r3;
vector<int> bits1(32, 0), bits2(32, 0), bits3(32, 0);


ll probBitIsZero(int bitNum) {
    for (int mask = 0; mask < (1 << 3); mask++) {
        if (__builtin_popcount(mask) % 2 != 0) continue;

        for (int i = 0; i < 32; i++) {
            if (mask)
        }
    }
}


int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;


    for (int i = l1; i <= r1; i++) {
        for (int j = 0; j < 32; j++) {
            if (i & (1 << j)) bits1[j]++;
        }
    }

    for (int i = l2; i <= r2; i++) {
        for (int j = 0; j < 32; j++) {
            if (i & (1 << j)) bits2[j]++;
        }
    }
    
    for (int i = l3; i <= r3; i++) {
        for (int j = 0; j < 32; j++) {
            if (i & (1 << j)) bits3[j]++;
        }
    }

    
    ll denom = (l1-r1) * (l2-r2) * (l3-r3);
    ll num = 
}