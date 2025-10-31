#include <bits/stdc++.h>
using namespace std;

void op1(string &s, int i, int j, int k) {
    string s1 = s.substr(0, i);
    string s2 = s.substr(i, j - i + 1);
    string s3 = s.substr(j + 1);

    
    // cout << s1 << " " << s2 << " " << s3 << "\n";
    s = s1 + s3;
    // cout << s << "\n";
    s.insert(k+1, s2);
    // cout << s << "\n";
}

void op2(string &s, int i, int j) {
    reverse(s.begin() + i, s.begin() + j + 1);
}

void op3(string &s, int i, char c) {
    string tmp = "";
    tmp += c;
    s.insert(i, tmp);
}

bool query(string &s, int i, int j) {
    while (s[i] == s[j] && i < j) i++, j--;
    return i >= j;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    string s; cin >> s;

    while (m--) {
        char type; cin >> type;
        if (type == 'M') {
            int x; cin >> x;
            if (x == 1) {
                int i, j, k; cin >> i >> j >> k;
                op1(s, i-1, j-1, k-1);
            } else if (x == 2) {
                int i, j; cin >> i >> j;
                op2(s, i-1, j-1);
            } else {
                int i; cin >> i;
                char c; cin >> c;
                op3(s, i-1, c);
            }
        } else {
            int i, j; cin >> i >> j;
            if (query(s, i-1, j-1)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}