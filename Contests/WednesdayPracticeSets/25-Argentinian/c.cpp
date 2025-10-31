#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> guys(2*n);
    for(int i = 0; i < n; i++) {
        cin >> guys[i];
        guys[i+n] = guys[i];
    }

    int res = n;
    map<int,int> freq;
    for(int i = 0; i < n; i++) {
        res += 2*freq[i+guys[i]];
        freq[i+guys[i]]++;
    }

    for(int i = n; i < n*2; i++) {
        res += 2*freq[i+guys[i]];
    }

    cout << res << '\n';
    return 0;
}/////.