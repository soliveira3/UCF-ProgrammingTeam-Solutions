#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int res = 0;
    map<int,int> guys;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        guys[tmp]++;
        if(guys[tmp+1] == 0) res++;
        else guys[tmp+1]--;
    }

    cout << res << '\n';
}