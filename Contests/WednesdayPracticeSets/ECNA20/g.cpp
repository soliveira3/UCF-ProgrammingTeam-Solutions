#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> pos(n), nums(n);
    iota(nums.begin(), nums.end(), 0LL);
    iota(pos.begin(), pos.end(), 0LL);
 
    if (n >= 2)
    for (ll i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        s = s.substr(1);
        t = t.substr(1);
        ll first = stoll(s)-1, second = stoll(t)-1;

        // cout << first << " " << second << '\n';

        if (pos[second] < pos[first])
        {
            ll pfirst = pos[first];
            ll psecond = pos[second];
                
            for (ll j = psecond; j < pfirst; j++)
                nums[j] = nums[j+1];
           
            nums[pfirst] = second;
        }

        
        for (ll j = 0; j < n; j++) pos[nums[j]] = j;
    }

    for (ll i = 0; i < n; i++)
        cout << 'T' << nums[i]+1LL << " ";

    cout << '\n';
}