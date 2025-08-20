#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
 
    ll longestString = 1;
    ll curLen = 1;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i] == s[i+1]) 
        {
            longestString = max(longestString, curLen+1);
            curLen++;
        }
 
        else curLen = 1;
    }
 
    cout << longestString << '\n';
 
}