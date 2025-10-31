#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(2 * n + 1), indeg(2 * n + 1), good(2 * n + 1), bad(2 * n + 1);
    vector<vector<int>> rev(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) cin >> arr[i], indeg[arr[i]]++, rev[arr[i]].push_back(i);

    queue<int> q;
    for (int i = 1; i <= 2 * n; i++) {
        if (indeg[i] == 0) q.push(i), good[i] = 1;
    }

    while (q.size()) {
        int i = q.front();
        // cout << i << "\n";
        q.pop();

        if (good[i]) bad[arr[i]] = 1;
        
        if (--indeg[arr[i]]) continue;
        if (!bad[i]) good[i] = 1;

        if (!bad[arr[i]]) good[arr[i]] = 1;
        q.push(arr[i]);
    }
    
    queue<pii> qq;
    // for (int i = 1; i <= 2 * n; i++) {
    //     if (bad[i] && (!good[arr[i]] && !bad[arr[i]])) {
    //         qq.push({arr[i], 1});
    //     }
    // }

    // while (qq.size()) {
    //     auto [i, g] = qq.front();
    //     cout << i << " " << g << " " << 1 - g << "\n";
    //     qq.pop();
    //     if (good[i] || bad[i]) continue;

    //     good[i] = g;
    //     bad[i] = 1 - g;

    //     qq.push({arr[i], 1 - g});
    // }

    // for (int i = 1; i <= 2 * n; i++) cout << i << ": " << bad[i] << "\n";

    for (int i = 1; i <= 2 * n; i++) {
        if (bad[i] && indeg[i] == 1) {
            qq.push({arr[i], 1});
            while (qq.size()) {
                auto [i, g] = qq.front();
                // cout << i << " " << g << "\n";
                qq.pop();
                if (good[i] || bad[i]) continue;
                
                good[i] = g;
                bad[i] = 1 - g;
                
                qq.push({arr[i], 1 - g});
            }
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (good[i] || bad[i]) continue;
        qq.push({i, 1});
        while (qq.size()) {
            auto [i, g] = qq.front();
            // cout << i << " " << g << "\n";
            qq.pop();
            if (good[i] || bad[i]) continue;

            good[i] = g;
            bad[i] = 1 - g;

            qq.push({arr[i], 1 - g});
        }
    }

    for (int i = 1 ; i <= 2 * n; i++) {
        if (good[i]) cout << i << " ";
    }
    cout << "\n";



    

    
}