#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define sz(x) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;

const ll mod = 1e9+7;

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string& s, int lim=256) {
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n,lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n-j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i-1];
            for(int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i-1], b = sa[i], x[b] = (y[a] == y[b] && y[a+j] == y[b+j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for(int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for(k && k--, j = sa[rank[i] - 1]; s[i+k] == s[j+k]; k++);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int n;
    cin >> s >> n;

    vi f(26);
    for(char c: s) f[c-'A']++;

    SuffixArray suf(s);
    vi sa = suf.sa;

    // for(int p: sa) cout << s.substr(p) << '\n';

    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int l = 0;
        int r = sz(sa);
        // auto l = sa.begin();
        // auto r = sa.end();
        int res = 1;
        int cnt = 0;
        for(int j = 0; j < sz(t); j++) {
            if(f[t[j]-'A'] == 0) {
                res = -1;
                break;
            }

            int lo = l, hi = r;
            while (lo < hi) {
                int m = (lo + hi) / 2;
                if (sa[m] + cnt >= s.size() || s[sa[m]+cnt] < t[j]) lo = m + 1;
                else hi = m;
            }

            l = lo;
            
            hi = r;
            while ((hi - lo) > 1) {
                int m = (lo + hi) / 2;
                if (sa[m] + cnt < s.size() && s[sa[m]+cnt] == t[j]) lo = m;
                else hi = m;
            }

            r = hi;
            
            // cout << j << " " << t[j] << ": " << l << " " << r << " " << cnt << " " << sa[l] << "\n";
            if (l == r || s[sa[l]+cnt] != t[j]) {
                res++;
                j--;
                cnt = 0;
                l = 0;
                r = sz(sa);
                continue;
            }
            cnt++;

            // cout << l << " " << lo << " " << hi << " " << j << " " << t[j] << '\n';

            // int lo = l;
            // int hi = r;
            // while(lo != hi) {
            //     int m = lo+(hi-lo)/2;
            //     if(s[sa[m] + j] != t[j]) lo = m + 1;
            //     else hi = m;
            // }

            // l = lo;
            // cout << l << '\n';
            // l = lower_bound(l, r, t[j], [&](int a, int b) {
            //     if(a+j >= n)return true;
            //     if(b+j >= n)return true;
            //     return s[a+j] < s[b+j];
            // });

            // r = upper_bound(l, r, j, [&](int a, int b) {
            //     if(a+j >= n)return true;
            //     if(b+j >= n)return true;
            //     return s[a+j] < s[b+j];
            // });
            // cout << (l-sa.begin()) << " " << (r-sa.begin()) << " " << j << " " << t[j] << '\n';

            // if(l == sa.end()) {
            //     l = sa.begin();
            //     r = sa.end();
            //     j--;
            //     res++;
            // }
        }

        cout << res << '\n';
    }
}