#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    set<int> pp;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if(!pp.count(d)) {
            res++;
            pp.insert(d);
        }
    }

    cout << min(k,res) << '\n';
}