// #pragma GCC optimize("trapv")
#include <bits/stdc++.h>
using namespace std;

#define int long long;

using ll = long long;
using ld = long double;
const ld eps = 1e-7;
const ll maxi = 1e14;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    map<ll, ll> posToW;
    map<ll, ll> posToCnt;
    multiset<pair<ld, ll>> priority; // maps w/cnt and pos
    posToW[(ll)-maxi] = 1;
    posToCnt[(ll)-maxi] = 0; 
    posToW[(ll)maxi] = 1;
    posToCnt[(ll)maxi] = 0;

    for (ll i = 0; i < n; i++) {
        ll p, w; cin >> p >> w;
        posToW[p] += w;
        posToCnt[p]++;
    }

    ld need = 0;
    for (auto [p, w] : posToW) {
        ll cnt = posToCnt[p];
        if (cnt == 0) continue;
        // cout << p << " " << w << " " << cnt << "\n";
        priority.insert({(ld)w / cnt, p});
        // cout << w << " " << cnt << " " << p << "\n";
        need += w * p;
    }

    // cout << need << "\n";
    ld res = 0;
    while (abs(need) > eps) {
        auto [pri, p] = *priority.rbegin();
        ll curW = posToW[p];
        ll curCnt = posToCnt[p];
        priority.erase(priority.lower_bound({pri, p}));

        // cout << p << " " << curW << " " << curCnt << "\n";

        if (need > 0) {
            // moving left
            auto itW = posToW.lower_bound(p);
            auto itCnt = posToCnt.lower_bound(p);
            itW--;
            itCnt--;
            // cout << itW->first << "!!!!!!!!!\n";
            ll dist = p - itW->first;
            ld maxDist = need / curW;
            if (maxDist < dist) {
                // cout << "wtfz\n";
                res += maxDist * curCnt;
                need = 0;
            } else {
                res += dist * curCnt;
                need -= dist * curW;
                auto it = priority.lower_bound({(ld)itW->second / itCnt->second-eps, itW->first});
                if (it != priority.end()) priority.erase(it);
                itW->second += curW;
                itCnt->second += curCnt;
                priority.insert({(ld)itW->second / itCnt->second-eps, itW->first});
            }
        } else {
            // moving right
            auto itW = posToW.upper_bound(p+eps);
            auto itCnt = posToCnt.upper_bound(p+eps);
            ll dist = itW->first - p;
            ld maxDist = -need / curW;
            if (maxDist < dist) {
                res += maxDist * curCnt;
                need = 0;
            }  else {
                res += dist * curCnt;
                need += dist * curW;
                auto it = priority.lower_bound({(ld)itW->second / itCnt->second-eps, itW->first});
                if (it != priority.end()) priority.erase(it);
                itW->second += curW;
                itCnt->second += curCnt;
                priority.insert({(ld)itW->second / itCnt->second-eps, itW->first});
            }
        }
    }


    cout << fixed << setprecision(10) << res << "\n";

}
