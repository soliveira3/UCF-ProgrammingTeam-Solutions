#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int s, n; cin >> s >> n;
    priority_queue<int, vector<int>, greater<int>> need, dontNeed;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        char ch; cin >> ch;
        if (ch == 'n') dontNeed.push(t);
        else need.push(t);
    }

    for (int t = 1; need.size() || dontNeed.size(); t++) {
        // cout << t << "!!!!\n";
        int taken = 0;
        int used = 0;
        while (dontNeed.size() && dontNeed.top() == t) {
            taken++;
            // cout << dontNeed.top() << " ";
            dontNeed.pop();
        }
        while (need.size() && need.top() == t) {
            taken++;
            used++;
            // cout << need.top() << " ";
            need.pop();
        } 
        if (taken > s || used > 1) {
            cout << "No\n";
            return 0;
        }
        if (taken == s) continue;
        if (need.size()) {
            // cout << need.top() << " ";
            used++, need.pop(), taken++;
        }
        while (taken < s && dontNeed.size()) {
            // cout << dontNeed.top() << " ";
            taken++, dontNeed.pop();
        }
    }

    cout << "Yes\n";

}