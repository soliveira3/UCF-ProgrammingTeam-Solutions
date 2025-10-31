#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,h,w;
    cin >> n >> h >> w;
    vector<array<int,2>> rain(n);
    for(int i = 0; i < n; i++) {
        char ch, cw;
        cin >> ch >> cw;
        rain[i] = {(ch == 'Y'), (cw == 'Y')};
    }

    for(int i = 0; i < n; i++) {
        if((h && !w) || (h && rain[i][0])) {
            cout << "Y ";
            h--;
            w++;
        } else cout << "N ";
        if((!h && w) || (w && rain[i][1])) {
            cout << "Y\n";
            w--;
            h++;
        } else cout << "N\n";
    }

}