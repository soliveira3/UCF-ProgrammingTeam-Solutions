#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

vl solve(vector<vl> &guys, int l, int r) {
    if (l + 1 == r) return guys[l];

    int m = (l + r) / 2;
    vl left = solve(guys, l, m);
    vl right = solve(guys, m, r);

    vl res(left.size() + right.size() - 1);

    for (int i = 0; i < left.size(); i++) {
        if (left[i] == 0) continue;
        for (int j = 0; j < right.size(); j++) {
            res[i + j] += left[i] * right[j];
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    char prev = s[0];

    vector<vl> guys;
    guys.push_back({1});

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != prev) {
            prev = s[i];
            guys.push_back({-(i * 2 + 1), 1});
        }
    }

    // for (auto x : guys) {
    //     cout << x[0] << " " << x[1] << "\n";
    // }

    
    vl res = solve(guys, 0, guys.size());
    int mult = 1;
    if ((s[0] == 'H') != (res[0] > 0)) mult = -1;
    reverse(res.begin(), res.end());

    cout << res.size() - 1 << "\n";
    for (ll i : res) {
        cout << mult * i << " ";
    }
    cout << "\n";

}