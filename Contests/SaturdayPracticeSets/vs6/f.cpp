#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int A = 0, B = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq1;
    priority_queue<pii> pq2;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == n) {
            cout << "impossible\n";
            return 0;
        }
        if (x == 0) continue;
        pq1.push({x, i});
        A += x;
    }
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == n) {
            cout << "impossible\n";
            return 0;
        }
        if (x == 0) continue;
        pq2.push({x, i});
        B += x;
    }

    if (A != B) {
        cout << "impossible\n";
        return 0;
    }

    vector<vector<int>> res(n);
    vector<pii> guys;
    guys.reserve((int)(2e6+2));
    while (pq1.size()) {
        auto [cnt1, u] = pq1.top(); pq1.pop();
        // cout << u + 1 << " " << pq2.size() << ": " << pq2.top().second << "\n"; 
        while (pq2.size() && cnt1) {
            auto [cnt2, v] = pq2.top(); pq2.pop();
            if (v == u) {
                guys.emplace_back(cnt2, v);
            } else {
                // cout << u + 1 << " " << v + 1 << "\n";
                res[u].push_back(v);
                if (cnt2 > 1) guys.emplace_back(cnt2-1, v);
                cnt1--;
            }
        }
        if (cnt1) {
            cout << "impossible\n";
            return 0;
        }
        while (guys.size()) {
            pq2.push(guys.back());
            guys.pop_back();
        }
    }
        

    cout << n << " " << A << "\n";
    for (int u = 0; u < n; u++) {
        for (int v : res[u]) {
            cout << u + 1 << " " << v + 1 << "\n";
        }
    }

}

// 5 9
// 1 5
// 3 2
// 4 1
// 5 4
// 5 5
// 5 3