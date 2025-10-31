#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int x; cin >> x;
    
    for (int i = 0; i < x - 1; i++) {
        s += s[i];
    }
    
    int n = s.size();
    ll res = 0;
    int lastE = -1e9;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') lastE = i;
        if (i < x-1) continue;
        res += max(0, lastE - (i - x));
    } 
    cout << res << "\n";
}