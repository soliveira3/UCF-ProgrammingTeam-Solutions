#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a)cin >> x;
    int lPtr = 0;
    int rPtr = n-1;
    int res = 0;
    while(lPtr <= rPtr) {
        if(a[lPtr] == a[rPtr]) {
            lPtr++;
            rPtr--;
            continue;
        }
        int tmpL = lPtr + 1;
        int tmpR = rPtr - 1;
        while(a[lPtr] != a[rPtr] && tmpL <= tmpR) {
            res++;
            if(a[lPtr] < a[rPtr]) {
                a[lPtr] += a[tmpL];
                tmpL++;
            } else {
                a[rPtr] += a[tmpR];
                tmpR--;
            }
        }

        if(a[lPtr] != a[rPtr]) res++;
        
        lPtr = tmpL;
        rPtr = tmpR;
    }

    cout << res << '\n';
}