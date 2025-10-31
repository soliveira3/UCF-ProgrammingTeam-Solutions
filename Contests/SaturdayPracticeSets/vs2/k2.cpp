#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(2 * n + 1), indeg(2 * n + 1), good(2 * n + 1), bad(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) cin >> arr[i], indeg[arr[i]]++;

    queue<int> q;
    for (int i = 1; i <= 2 * n; i++) {
        if (!indeg[i]) q.push(i);
    }


    while (q.size()) {
        int i = q.front();
        q.pop();
        if (good[i] || bad[i]) continue;

        int nxt1 = arr[i];
        int nxt2 = arr[nxt1];

        good[i] = 1;
        bad[nxt1] = 1;
        --indeg[nxt1];
        if (!--indeg[nxt2]) q.push(nxt2);
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (!good[i] && !bad[i]) {
            q.push(i);
            while (q.size()) {
                int i = q.front();
                q.pop();
                if (good[i] || bad[i]) continue;

                int nxt1 = arr[i];
                int nxt2 = arr[nxt1];

                good[i] = 1;
                bad[nxt1] = 1;
                --indeg[nxt1];
                if (!--indeg[nxt2]) q.push(nxt2);
            }
        }
    }

    for (int i = 1 ; i <= 2 * n; i++) {
        if (good[i]) cout << i << " ";
    }
    cout << "\n";



    
}