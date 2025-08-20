#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll q, a, b;
    cin >> q;
 
    while (q--)
    {
        cin >> a >> b;
        cout << (((2 * a - b) % 3 || (2 * a - b) < 0 || (2 * b - a) % 3 || (2 * b - a) < 0) ? "NO\n" : "YES\n");
    }
 
	return 0;
}