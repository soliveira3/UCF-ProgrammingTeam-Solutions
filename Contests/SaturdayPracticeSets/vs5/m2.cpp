#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,d;
    cin >> n >> d;
    vector<array<int,2>> guys(n+5, {-1,-1}); // Build off prev or make new shield? (Last idx in shield)
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        // Haven't taken anything
        if(guys[tmp][0] == -1 && guys[tmp][1] == -1) {
            guys[tmp] = {max(i,d-1),i+d-1};
            continue;
        }

        // Can make new shield
        if(i - guys[tmp][0] > d) {
            guys[tmp][0] = i;
        } else {
            guys[tmp][0] = guys[tmp][1];
        }

        // Can build off of the prev
        if(guys[tmp][1] >= i) {
            continue;
        }

        // Can't make new shield or build off prev
        if(guys[tmp][0] != i) guys[tmp] = {(int)1e9,(int)1e9};
    }

    for(int i = 0; i <= n; i++) {
        if(guys[i][0] != 1e9 && guys[i][1] != 1e9) {
            cout << i << '\n';
            return 0;
        }
    }
}