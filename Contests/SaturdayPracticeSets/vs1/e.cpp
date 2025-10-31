#pragma GCC optimize("Ofast,inline,unroll-loops")
#include <bits/stdc++.h>
using namespace std;


using ll = long long;
#define int long long


// struct Node {
//     int lo, hi, m, val;
//     Node *left, *right;
    
//     // Each node stores the rightmost position for i
//     Node(int l, int r): lo(l), hi(r), m((lo+hi)/2), val(-1) {
//         if (l + 1 == r) {
//             left = right = 0;
//         } else {
//             left = new Node(lo, m);
//             right = new Node(m, hi);
//         }
//     }

//     void update(int i, int v) {
//         if (lo + 1 == hi) {
//             val = v;
//             return;
//         }
//         // cout << lo << " " << hi << ": " << v << "\n";
//         if (i < m) left->update(i, v);
//         else right->update(i, v);
//         val = max(left->val, right->val);
//     }

//     int query(int l, int r) {
//         if (l <= lo && hi <= r) return val;
//         if (r <= lo || hi <= l) return -1;
//         return max(left->query(l, r), right->query(l, r));
//     }


// };

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;
    vector<ll> dp(n, 1e15);
    // iota(dp.begin(), dp.end(), 1);
    dp[0] = 0;
    ll best = 1e15;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        dp[i] = i * i;
        // cout << i << ":\n";
        for (int j = i - 1; j >= 0; j--) {
            // if ((i-j-1)*(i-j-1) >= best) break;
            if (i - j >= 350) break;
            
            if (nums[i] >= nums[j]) dp[i] = min(dp[i], dp[j] + (i-j-1)*(i-j-1));
        }
        best = min(best, dp[i] + (n-i-1)*(n-i-1));
        // cout << best << "\n\n";
    }

    // for (int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // } cout << "\n";


    cout << best << "\n";

    // Node *ST = new Node(0, 1e6+5);

    // for (int i = 0; i < n; i++) {
    //     int x = nums[i];
        
    //     int idx = ST->query(0, nums[i]+1);
    //     cout << i << " " << idx << "\n";
    //     if (idx == -1) {
    //         dp[i] = (ll)i * i;
    //         best = min(best, dp[i] + (ll)(n-i-1)*(n-i-1));
    //     } else {
    //         dp[i] = dp[idx] + (ll)(i - idx - 1) * (i - idx - 1);
    //         best = min(best, dp[idx] + (ll)(i - idx - 1) * (i - idx - 1) + (ll)(n-i-1)*(n-i-1));
    //     }


    //     // cout << "update " << nums[i] << " with " << i << "\n"; 
    //     ST->update(nums[i], i);



    //     // auto it = mp.upper_bound(x);
    //     // it--;

    //     // auto [lastIdx, val] = it->second;
    //     // ll len = i - lastIdx - 1;

    //     // // if (it->first != x) mp[x] = {}

    //     // mp[x] = {i, len * len + val};
    //     // best = min(best, len * len + val + (ll)(n-i-1) * (n-i-1));

    //     // cout << i << ": ";
    //     // for (auto [x, y] : mp) {
    //     //     cout << x << ": " << y[0] << " " << y[1] << "; ";
    //     // }
    //     // cout << "\n";
    // }

    // cout << best << "\n";
}