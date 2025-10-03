#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
 
struct AhoCorasick
{
    enum
    {
        alpha = 26,
        first = 'a'
    }; // change this!
 
    struct Node
    {
        // (nmatches is optional)
        int back, next[alpha], start = -1, end = -1, nmatches = 0;
        Node(int v) { memset(next, v, sizeof(next)); }
    };
 
    vector<Node> N;
    vi backp;
 
    void insert(string &s, int j)
    {
        assert(!s.empty());
        int n = 0;
        for (char c : s)
        {
            int &m = N[n].next[c - first];
            if (m == -1)
            {
                n = m = sz(N);
                N.emplace_back(-1);
            }
            else
                n = m;
        }
        if (N[n].end == -1)
            N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
    }
 
    AhoCorasick(vector<string> &pat) : N(1, -1)
    {
        rep(i, 0, sz(pat)) insert(pat[i], i);
        N[0].back = sz(N);
        N.emplace_back(0);
 
        queue<int> q;
        for (q.push(0); !q.empty(); q.pop())
        {
            int n = q.front(), prev = N[n].back;
            rep(i, 0, alpha)
            {
                int &ed = N[n].next[i], y = N[prev].next[i];
                if (ed == -1)
                    ed = y;
                else
                {
                    N[ed].back = y;
                    (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
                    N[ed].nmatches += N[y].nmatches;
                    q.push(ed);
                }
            }
        }
    }
 
    vi find(string word)
    {
        int n = 0;
        vi res; ll count = 0;
        for (char c : word)
        {
            n = N[n].next[c - first];
            res.push_back(N[n].end);
            count += N[n].nmatches;
        }
        return res;
    }
 
    vector<vi> findAll(vector<string> &pat, string word)
    {
        vi r = find(word);
        vector<vi> res(sz(word));
        rep(i, 0, sz(word))
        {
            int ind = r[i];
            while (ind != -1)
            {
                res[i - sz(pat[ind]) + 1].push_back(ind);
                ind = backp[ind];
            }
        }
        return res;
    }
};
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    string s;
    cin >> s;
    ll n = sz(s);
 
    ll k;
    cin >> k;
    vector<string> pat;
 
    rep(i, 0, k)
    {
        string t;
        cin >> t;
        pat.push_back(t);
    }
 
    AhoCorasick ac(pat);
 
    vector<bool> found(k, false);
    vi res = ac.find(s);
 
    rep(i, 0, sz(res))
    {
        int x = res[i];
        while (x != -1)
        {
            if (found[x]) break;
            found[x] = true;
            x = ac.backp[x];
        }
    }
 
    rep (i, 0, k) cout << (found[i] ? "YES\n" : "NO\n");
}