#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

struct ST {
    ll lo, hi, mid;
    ll val, number;
    ST *left = nullptr; ST *right = nullptr;
    ST (ll l, ll r) {
        lo = l; hi = r;
        mid = (lo + hi) / 2;
        val = 0;
        number = 0;
    }

    ll merge(ll a, ll b) { return a + b; }

    void check() {
        if (!left) {
            left = new ST(lo, mid);
            right = new ST(mid+1, hi);
        }
    }

    void add(ll i, ll v) {
        if (lo == hi) {
            val += (v*i);
            number += v;
            return;
        }

        check();
        if (i <= mid) left->add(i, v);
        else right->add(i, v);
        val = merge(left->val, right->val);
        number = merge(left->number, right->number); 
    }

    // CHECK THIS
    pair<ll, ll> lastXGuysSum(ll X) {
        if (number <= X)
            return {val, number};

        if (lo == hi) { 
            pair<ll, ll> ret = {val, number};
            if (X < number) ret = {lo*X, X};
            return ret;
        }

        pair<ll, ll> resRight = right->lastXGuysSum(X);
        if (resRight.second < X) {
            pair<ll, ll> resLeft = left->lastXGuysSum(X-resRight.second);
            resRight.first += resLeft.first;
            resRight.second += resLeft.second;
        } 

        return resRight;
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);


    ll n, k, l;
    cin >> n;
    vector<ll> top(n), bottom(n);
    for (ll i = 0; i < n; i++) { cin >> top[i]; }
    for (ll i = 0; i < n; i++) { cin >> bottom[i]; }
    cin >> k >> l;

    // set current for first k
    ST st(1, 1e9+5);
    ll topSum = 0;
    for (ll i = 0; i < k; i++) {
        st.add(bottom[i], 1);
        topSum += top[i];
    }

    // going throught each possible k values
    ll p1 = k-1, p2 = n;
    ll mxAns = 0;
    while (p1 >= -1) {

        ll totalSum = topSum + st.lastXGuysSum(l).first;
        mxAns = max(totalSum, mxAns);

        // updating the sides
        if (p1 >= 0) {
            st.add(bottom[p1], -1);
            topSum -= top[p1];
        }
        p1--;
        p2--;
        st.add(bottom[p2], 1);
        topSum += top[p2];
    }

    cout << mxAns << '\n';
}