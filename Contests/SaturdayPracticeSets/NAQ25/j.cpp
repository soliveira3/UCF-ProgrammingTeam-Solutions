#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef long double ld;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 0; i < 100; i++) {
        int a;
        cin >> a;
        if(i == 99) cout << ((a%10) == 0 ? 10 : (a%10)) << '\n';
    }
}