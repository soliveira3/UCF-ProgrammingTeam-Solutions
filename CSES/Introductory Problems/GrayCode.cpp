#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n; cin >> n;
 
    for (int i = 0; i < (1 << n); i++)
    {
        ll grey = (i ^ (i >> 1));
 
        for (int j = 0; j < n; j++)
            cout << (grey & (1 << n-j-1) ? "1" : "0");
 
        cout << '\n';
    }
 
    return 0;
}