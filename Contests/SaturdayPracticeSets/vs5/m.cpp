#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct DSU {
    int n;
    vi lo, hi, sz, par;

    DSU(vi &guys) {
        n = guys.size();
        lo = hi = guys;
        par = vi(n);
        sz = vi(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool join(int u, int v) {
        int pu = find(u), pv = find(v);
        if (find(u) == find(v)) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        lo[pv] = min(lo[pv], lo[pu]);
        hi[pv] = max(hi[pv], hi[pu]);
        sz[pv] += sz[pu];
        par[pu] = pv;
        return true;
    }
};

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n,d;
    cin >> n >> d;
    vector<vector<int>> guys(n + 5); 
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        guys[x].push_back(i);
    }

    for (int guy = 0; guy < guys.size(); guy++) {
        if (guys[guy].size() <= 1) {
            cout << guy << "\n";
            return 0;
        }

        DSU dsu(guys[guy]);

        for (int i = 1; i < guys[guy].size(); i++) {
            if (guys[guy][i] - dsu.lo[dsu.find(i-1)] < d) dsu.join(i-1, i);
        }

        vector<int> pars;
        for (int i = 0; i < guys[guy].size(); i++) {
            if (!pars.size() || pars.back() != dsu.find(i)) pars.push_back(dsu.find(i));
        }

        int works = true;
        int lastTaken = -1e9;
        for (int i : pars) {
            if (lastTaken != -1e9 && dsu.lo[i] - lastTaken - 1 < d) {
                works = false;
                break;
            }
            int len = dsu.hi[i] - dsu.lo[i] + 1;
            int ub = max(0, max(lastTaken + d + 1, dsu.lo[i] - (d - len)));
            dsu.lo[i] = ub;
            
            len = dsu.hi[i] - dsu.lo[i] + 1;
            dsu.hi[i] += max(0, d - len);

            lastTaken = dsu.hi[i];
            // cout << dsu.lo[i] << " " << dsu.hi[i] << "\n";
        }

        if (works) {
            cout << guy << "\n";
            return 0;
        }


        // // cout << guy << ":\n";
        // // time to start
        // int early = max(0, guys[guy][0] - d + 1);
        // int late = guys[guy][0];
        // int works = true;
        // int lastGuy = -1e9;
        // for (int x : guys[guy]) {
        //     // cout << early << " " << late << "\n";
        //     if (x <= late + d - 1) {
        //         // if we can combine
        //         early = max(early, x - d + 1);
        //         if (early > late) {
        //             works = false;
        //             break;
        //         }
        //     } else {
        //         // if can start a new one
        //         if (early + 2 * d <= x) {
        //             early = max(x - d + 1, lastGuy + d);
        //             late = x;
        //         } else {
        //             works = false;
        //             break;
        //         }
        //     }
        //     lastGuy = x;
        // }
        // if (works) {
        //     cout << guy << "\n";
        //     return 0;
        // }
    }
}