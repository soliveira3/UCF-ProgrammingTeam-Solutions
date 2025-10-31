#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (int)b; ++i)
#define int long long

vector<vector<int>> m;
vector<int> op(vector<int> vec) {
    int N = vec.size();
    vector<int> ret(vec.size());
    rep(i,0,N) rep(j,0,N) ret[i] += (m[i][j] * vec[j])%37, ret[i] %= 37;
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    m = vector<vector<int>>(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> m[i][j];
    }

    map<char, int> guys;
    map<int, char> other;
    for(int i = 'A'; i <= 'Z'; i++) guys[i] = i-'A', other[i-'A'] = i;
    for(int i = '0'; i <= '9'; i++) guys[i] = i-'0'+26, other[i-'0'+26] = i;
    guys[' '] = 36;
    other[36] = ' ';

    string s;
    getline(cin, s);
    getline(cin, s);
    string res = "";
    for(int i = s.size(); i%n != 0; i++) s += ' ';
    for(int i = 0; i < s.size(); i+=n) {
        vector<int> cur;
        for(int argh = 0; argh < n; argh++) cur.push_back(guys[s[i+argh]]);
        auto pp = op(cur);
        for(int aaa = 0; aaa < n; aaa++) res += other[pp[aaa]];
    }
    cout << res << '\n';
}