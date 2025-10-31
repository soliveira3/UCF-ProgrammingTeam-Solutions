#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    string t = "TAP";
    int idx = 0;
    for(char c: s) {
        if(c == t[idx]) idx++;
        if(idx == t.size())break;
    }

    if(idx == t.size()) cout << "S\n";
    else cout << "N\n";
    return 0;
}