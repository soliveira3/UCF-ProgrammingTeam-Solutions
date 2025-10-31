#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)


const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    Node(vll &v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo]; 
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r-> set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val); 
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};



ll a, b, n;
void findFactors(ll x, Node &st, ll wordSize)
{
    for (int i = 1; i*i <= x; i++)
        if ((x/i)*i == x)
        {
            st.add(i, i+wordSize+1, wordSize+1);
            st.add((x/i), (x/i)+wordSize+1, wordSize+1);
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    getline(cin, s);
    cout << s << '\n';

    n = sz(s);
    cin >> a >> b;

    vll wordSizes;

    ll start = 0;
    rep (i, 0, n)
        if (i == n-1 || s[i+1] == ' ')
        {    
            wordSizes.push_back(i+1-start);
            start = i+2;
        }

    vll temp(sz(s)+5, wordSizes[0]);
    Node st(temp, 0, sz(s)+5);

    ll length = 0;
    for (int i = 0; i < sz(wordSizes)-1; i++) {
        length += wordSizes[i];
        findFactors(length, st, wordSizes[i+1]);
        length++;
    }

    rep (i, a, b+1) cout << st.query(i, i+1) << '\n';
}