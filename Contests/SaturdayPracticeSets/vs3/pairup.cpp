#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool solve(map<ll, int> mp, ll mid) {
    while (mp.size()) {
        auto &[t1, cnt1] = *mp.begin();
        auto it = mp.upper_bound(mid - t1);
        if (it == mp.begin()) return false;
        it--;
        auto &[t2, cnt2] = *it;
        assert(t1 + t2 <= mid);

        // cout << t1 << " " << cnt1 << " " << t2 << " " << cnt2 << "\n";
        
        if (t1 == t2) {
            if (cnt1 % 2 == 0) mp.erase(mp.begin());
            else return false;
            continue;
        }
        int take = min(cnt1, cnt2);
        cnt1 -= take;
        cnt2 -= take;
        if (cnt1 == 0) mp.erase(mp.begin());
        if (cnt2 == 0) mp.erase(it);
    }
    return true;
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        mp[y] += x;
    }

    ll lo = 0, hi = 1e10;

    // 000001111. first 1
    while (lo < hi) {
        ll m = (lo + hi) / 2;
        // cout << lo << " " << m << " " << hi << "\n";
        if (solve(mp, m)) hi = m;
        else lo = m + 1;
    }

    cout << hi << "\n";
    
    // cout << solve(mp, 2500000000) << "\n";
    // cout << solve(mp, 9) << "\n";
    // cout << solve(mp, 10) << "\n";
    // cout << solve(mp, 11) << "\n";

}