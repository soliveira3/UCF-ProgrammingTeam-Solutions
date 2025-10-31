#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (auto &y : nums) cin >> y;

    int best = 1;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        for (; j < n; j++) {
            if (nums[j] - nums[j-1] > x) break;
        }
        best = max(best, j - i);
    }
    cout << best << "\n";
}