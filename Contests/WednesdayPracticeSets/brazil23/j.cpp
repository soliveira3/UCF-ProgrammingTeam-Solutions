#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int a = 0, b = 0;
    int x;

    vector<int> count(14, 4);

    cin >> x;
    count[x]--;
    a += min(x, 10);
    cin >> x;
    count[x]--;
    a += min(x, 10);
    
    cin >> x;
    count[x]--;
    b += min(x, 10);
    cin >> x;
    count[x]--;
    b += min(x, 10);


    for (int i = 0; i < n; i++) {
        cin >> x;
        count[x]--;
        a += min(x, 10);
        b += min(x, 10);
    }



    int ans = -1;
    for (int i = 1; i <= 13; i++) {
        if (count[i] > 0 && ((b+min(i, 10) == 23) || (b+min(i, 10) <= 23 && a+min(i, 10) > 23))) {
            ans = i;
            break;
        }
    }
    
    cout << ans << '\n';
}