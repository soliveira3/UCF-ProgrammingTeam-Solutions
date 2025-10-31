#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;


vector<pair<string, string>> threes =
{
    {"000", "000"},
    {"001", "201"},
    {"010", "210"},
    {"011", "211"},
    {"100", "200"},
    {"101", "220"},
    {"110", "222"},
    {"111", "000"}
};



void encode() {
    if (n == 1) {
        cout << s << '\n';
        return;
    }
    if (n == 2) {
        if (s[0] != s[1]) s[0] = '2';
        cout << s << '\n';
        return;
    }
    if (n == 3) {
        for (auto pr : threes)
            if (pr.first == s) {
                cout << pr.second << '\n';
                return;
            }
    }

    // NORMAL CASES
    string t = s;
    bool isFullyAlternating = false;
    // adding twos until alternating stops

    for (ll i = 0; i < (s.size()); i++) {
        t[i] = '2';
        if (i == s.size()-1) isFullyAlternating = true;
        if (i == s.size()-1 || s[i] == s[i+1]) break;
    }

    // multiple 2s if alternating
    if (isFullyAlternating) {
        t = s;
        for (ll i = 0; i < s.size(); i+=2)
            t[i] = '2';
    }

    cout << t << '\n';
}


void decode(){
    if (n == 1) {
        cout << s << '\n';
        return;
    }
    if (n == 2) {
        
        if (s[1] == '2') swap(s[0], s[1]);

        if (s[0] == s[1]) cout << s << '\n';        
        else if (s[1] == '0') cout << "10\n"; 
        else cout << "01\n"; 
        return;
    }
    if (n == 3) {
        for (auto pr : threes)
            if (pr.second == s) {
                cout << pr.first << '\n';
                return;
            }
    }

    
    // realigning the string
    string t = s;
    ll start = 0, finalStart = 0, altCount = 0;
    for (; start < n; start++)
        if (s[start] == '2' && s[((start+n-1LL)%n)] != '2') {
            finalStart = start;
            altCount++;
        }

    // alternating case
    if (altCount > 1)
        for (start = 0; start < n; start++)
            if (s[start] == '2' && s[((start+1)%n)] != '2' && s[(start+2)%n] == '2') {
                finalStart = start;
                break;
            }

    start = finalStart;

    ll ct = 0;
    for (; ct < n; start++, ct++) {
        t[ct] = s[start%n];
    }


    // Alternating case
    if (t[0] == '2' && t[1] != '2' && t[2] == '2') {
        bool numOdd = (t[1]-'0');
        for (ll i = 0; i < t.size(); i++)
            cout << ((i & 1) ? numOdd : !numOdd);
        cout << '\n';
        return;
    }

    // normal case
    ll idx = 0;
    // going to the final 2 index
    for (idx = 0; idx < t.size()-1; idx++)
        if (t[idx+1] != '2') break;

    t[idx] = t[idx+1];
    idx--;

    for (; idx >= 0; idx--)
        t[idx] = ((t[idx+1] == '0') ? '1' : '0');

    cout << t << '\n';
}


// main and inpute
int main() {
    string op;
    cin >> op >> n >> s;

    if (op[0] == 'E') encode();
    else decode();
}