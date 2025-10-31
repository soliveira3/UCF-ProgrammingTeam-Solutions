#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef long double ld;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ld ox = 144, oy = 84;
    int scoreA = 0, scoreB = 0;

    rep (tx, 0, 10) {
        int n, m;
        cin >> n;
        
        vector<ld> a, b;
        rep (i, 0, n) {
            ld x, y;
            cin >> x >> y;
            x = abs(ox-x);
            y = abs(oy-y);

            a.push_back(sqrt(x*x+y*y));
        }

        cin >> m;
        rep (i, 0, m) {
            ld x, y;
            cin >> x >> y;
            x = abs(ox-x);
            y = abs(oy-y);

            b.push_back(sqrt(x*x+y*y));
        }

        if (n == 0 && m == 0) continue;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (n == 0) {
            scoreB += b.size();
            continue;
        }

        if (m == 0) {
            scoreA += a.size();
            continue;
        }
        
        if (a[0] < b[0]) {
            rep (i, 0, sz(a))
                if (a[i] < b[0]) scoreA++;
        }

        else {
            rep (i, 0, sz(b))
               if (b[i] < a[0]) scoreB++;
        }
    }

    cout << scoreA << " " << scoreB << '\n';
}