#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x, y;
    cin >> n >> x >> y;

    if (x + y > n+1) {
        cout << "no\n";
        return 0;
    }

    bool reversed = false;
    if (y < x) {
        swap(x, y);
        reversed = true;
    }

    vector<int> a(n, -1);
    for (int i = 1; i <= x-1; i++)
        a[i-1] = i;

    a[x-1] = n;

    if (a[n-y+1] != -1) {
        cout << "no\n";
        return 0;
    }

    int sz = n-1;
    for (int i = n-y+1; i < n; i++) {
        a[i] = sz;
        sz--;
    }

    for (int i = x; i < n, a[i] == -1; i++) {
        a[i] = sz;
        sz--;
    }


    if (*min_element(a.begin(), a.end()) <= 0) {
        cout << "no\n";
        return 0;
    }

    if (reversed) reverse(a.begin(), a.end());
    cout << "yes\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}