#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (int)b; i++)
#define sz(x) (x).size()
typedef long long ll;
typedef vector<ll> vll;
const int mod = 1e9+7;
const int alph = 31;

ll fastexpo(ll num, int e) {
    if (e == 0) return 1;
    ll res = fastexpo(num, e / 2);
    res = (res * res) % mod;
    if (e & 1) res = (res * num) % mod;
    return res;
}
 
int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll patternRows, patternCol, r, c;
    cin >> patternRows >> patternCol;

    vector<string> pattern(patternRows);
    rep (i, 0, patternRows) cin >> pattern[i];

    cin >> r >> c;
    vector<string> text(r);
    rep (i, 0, r) cin >> text[i];

    ll hashKey = 0;
    ll currPow = 1;
    for(int i = 0; i < patternRows; i++) {
        for(int j = 0; j < patternCol; j++) {
            hashKey += (((ll)pattern[i][j]-'a'+1)*currPow)%mod;
            hashKey %= mod;
            currPow = (currPow*alph)%mod;
        }
        for(int j = patternCol; j < c; j++)currPow = (currPow*alph)%mod;
    }

    vector<vector<ll>> hashes(r,vector<ll>(c));
    currPow = 1;
    hashes[0][0] = (ll)(text[0][0]-'a'+1);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!j) hashes[i][j] = ((ll)(text[i][j]-'a'+1)*currPow) % mod;
            else hashes[i][j] = (hashes[i][j-1] + (((ll)(text[i][j]-'a'+1))*currPow)%mod) % mod;
            // cout << i << " " << j << ": " << ((ll)(text[i][j]-'a'+1)) << '\n';
            currPow = (currPow * alph) % mod;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!i) continue;
            else hashes[i][j] = (hashes[i-1][j] + hashes[i][j]) % mod;
        }
    }

    // cout << hashes[0][1] << "\n";

    vector<vector<int>> display(r, vector<int>(c, 0));

    for(int i = patternRows-1; i < r; i++) {
        for(int j = patternCol-1; j < c; j++) {
            ll subhash = hashes[i][j] - (i > patternRows-1 ? hashes[i-patternRows][j] : 0) - (j > patternCol-1 ? hashes[i][j-patternCol] : 0);
            subhash = (subhash % mod + mod) % mod;
            if (i > patternRows-1 && j > patternCol-1) subhash = (subhash + hashes[i-patternRows][j-patternCol]) % mod;
            int cnt = (i - patternRows+1) * c + (j - patternCol+1);
            subhash = (subhash * fastexpo(fastexpo(alph, cnt), mod-2)) % mod;
            // cout << i << " " << j << ": " << cnt << "\n";
            // cout << i << " " << j << ": " << cnt << " " << subhash << " " << hashKey << "\n"; 

            if (subhash == hashKey) {
                for (int cc = j; cc > j - patternCol; cc--) {
                    if (display[i][cc]) break;
                    display[i][cc] = patternRows;
                }
                // cout << "IN HERE\n";
                // for (int rr = i; rr > i - patternRows; rr--) {
                //     if (display[rr][j]) break;
                //     for (int cc = j; cc > j - patternCol; cc--) {
                //         if (display[rr][cc]) break;
                //         display[rr][cc] = 1;
                //     }
                // }
            }
        }
        // cout << "\n";
    }

    for (int rr = r-1; rr > 0; rr--) {
        for (int cc = 0; cc < c; cc++) {
            display[rr-1][cc] = max(display[rr-1][cc], display[rr][cc]-1); 
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (display[i][j]) cout << text[i][j];
            else cout << ".";
        }
        cout << "\n";
    }
    // cout << "\n";
}