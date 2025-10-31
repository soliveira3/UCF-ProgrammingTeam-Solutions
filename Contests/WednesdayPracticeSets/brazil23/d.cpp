#include <bits/stdc++.h>
using namespace std;

int n;

int hui(int tar) {
    vector<int> res(1 << n, 1e9);
    res[1 << (n - 1)] = 0;
    queue<int> q;
    q.push(1 << (n - 1));
    while (q.size()) {
        auto i = q.front();
        q.pop();
        if (i == tar) return res[i];

        int a = i / 2;
        int b = i + ((1 << n) - i) / 2;
        if (res[a] == 1e9) {
            res[a] = res[i] + 1;
            q.push(a);
        }
        if (res[b] == 1e9) {
            res[b] = res[i] + 1;
            q.push(b);
        }
    }
    assert(false);
    return 1e9;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, y; cin >> n >> x >> y;

    cout << max(hui(x), hui(y)) << "\n";
}