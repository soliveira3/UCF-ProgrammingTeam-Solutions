#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int lo,hi,mid;
    int val;
    node* left = nullptr;
    node* right = nullptr;
    node(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
    }

    void check() {
        if(!left) {
            left = new node(lo, mid);
            right = new node(mid+1, hi);
        }
    }

    int query(int l, int r) {
        if(r < lo || l > hi) return 0;
        if(l <= lo && hi <= r) return val;
        check();
        return left->query(l,r) + right->query(l,r);
    }

    void update(int i, int v) {
        if(lo == hi) return void(val += v);
        check();
        if(i <= mid) left->update(i,v);
        else right->update(i,v);
        val = left->val+right->val;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> guys(n);
    node forward(0,1e9+5);
    node backward(0,1e9+5);
    for(int i = 0; i < n; i++) {
        cin >> guys[i];
        backward.update(guys[i],1);
    }
    

    int res = 0;
    for(int i = 0; i < n; i++) {
        int a = backward.query(guys[i]+1, 1e9+1);
        int b = forward.query(guys[i]+1, 1e9+1);
        int sm = min(a,b);
        int bg = max(a,b);
        if(sm*2 < bg) {
            res++;
        }
        forward.update(guys[i],1);
        backward.update(guys[i],-1);
    }
    cout << res << '\n';
    return 0;
}