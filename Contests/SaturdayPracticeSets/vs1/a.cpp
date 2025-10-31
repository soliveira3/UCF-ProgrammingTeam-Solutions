#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string a,b;
    cin >> a >> b;
    vector<int> freqa(26);
    vector<int> freqb(26);

    for(char c: a) {
        freqa[c-'a']++;
    }

    for(char c: b) {
        freqb[c-'a']++;
    }

    string res = "";
    for(int i = 0; i < 26; i++) {
        int freq = max(freqa[i],freqb[i]);
        for(int j = 0; j < freq; j++) res += (char)('a'+i);
    }

    cout << res << '\n';
    return 0;
}