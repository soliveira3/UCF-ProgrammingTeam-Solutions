#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    for(int i = 0; i < n-1; i++) {
        if(s[i] != 'a' || s[i+1] != 'a')continue;
        while(s[i] == 'a') res++, i++;
    }

    cout << res << '\n';
}