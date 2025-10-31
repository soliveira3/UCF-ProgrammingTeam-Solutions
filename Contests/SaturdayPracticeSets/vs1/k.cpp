#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, p, m; cin >> n >> k >> p >> m;
    vector<int> nums(m);
    vector<int> lastIdx(k+1, -1e9), freq(k+1);
    for (auto &x : nums) cin >> x, freq[x]++;


    for (int i = 0; i < m; i++) {
        int x = nums[i];
        if (i - lastIdx[x] < p) {
            cout << "impossible\n";
            return 0;
        }
        lastIdx[x] = i;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= k; i++) {
        if (lastIdx[i] <= m - p) pq.push({freq[i], i});
    }

    // while (pq.size()) {
    //     auto [x, y] = pq.top();
    //     cout << x << " " << y << "\n";
    //     pq.pop();
    // }


    for (int i = m; i < n; i++) {
        if (pq.empty()) {
            cout << "impossible\n";
            return 0;
        }
        
        if (i != m && i - p >= 0) {
            pq.push({freq[nums[i-p]], nums[i-p]});
        }
        auto [f, y] = pq.top();
        pq.pop();
        nums.push_back(y);
        freq[y]++;
    }

    for (auto x : nums) cout << x << " ";
    cout << '\n';
}