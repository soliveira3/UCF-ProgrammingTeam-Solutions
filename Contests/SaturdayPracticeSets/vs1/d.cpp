#include <bits/stdc++.h>
using namespace std;

long double p,r,y;
const long double EPS = 1e-6;
array<long double,4> good(long double m) {
    array<long double,4> res = {1e9,1e9,1e9,1e9};
    long double plus = y+r+p;
    long double minus = y-p-r;
    // cout << "AT " << m << ": \n";
    
    // try n
    long double n,e,w,s;
    n = m;
    e = (plus-2*n)/2;
    w = e-p;
    s = n-r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == n) return {n,e,s,w};

    // try e
    e = m;
    n = (plus-2*e)/2;
    w = e-p;
    s = n-r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == e) return {n,e,s,w};

    s = m;
    w = (minus-2*s)/2;
    e = w+p;
    n = s+r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == s) return {n,e,s,w};

    w = m;
    s = (minus-2*w)/2;
    e = w+p;
    n = s+r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == w) return {n,e,s,w};

    n = -m;
    e = (plus-2*n)/2;
    w = e-p;
    s = n-r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == -n) return {n,e,s,w};

    // try e
    e = -m;
    n = (plus-2*e)/2;
    w = e-p;
    s = n-r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == -e) return {n,e,s,w};

    s = -m;
    w = (minus-2*s)/2;
    e = w+p;
    n = s+r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == -s) return {n,e,s,w};

    w = -m;
    s = (minus-2*w)/2;
    e = w+p;
    n = s+r;
    // cout << n << " " << e << " " << w << " " << s << '\n';

    if(abs(n+e+w+s-y) <= EPS && max({abs(n),abs(e),abs(w),abs(s)}) == -w) return {n,e,s,w};
    return res;
}

long double print(long double x) {
    if (abs(x) < EPS) return 0;
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q;
    cin >> q;
    while(q--) {
        cin >> p >> r >> y;

        long double lo = 0;
        long double hi = 1e8;

        array<long double, 4> res;
        for(int i = 0; i < 200; i++) {
            long double m = (lo+hi)/2;
            // cout << "TRYING " << m << " GOT " << good(m)[0] << " " << good(m)[1] << " " <<good(m)[2] << " " << good(m)[3] << '\n';
            if(good(m)[0] == 1e9) lo = m;
            else hi = m;
        }

        res = good(hi);
        cout << fixed << setprecision(7);
        cout << print(res[0]) << " " << print(res[1]) << " " << print(res[2]) << " " << print(res[3]) << '\n';
        // cout << "-------------------------------------\n";
    }
}