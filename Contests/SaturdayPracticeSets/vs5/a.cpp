#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    set<int> st;
    st.insert(x);
    st.insert(x+1);
    st.insert(-(x-y-1) + x);

    if ((-(x-y-1) + x+1) % (x+y) == 0)
        st.insert((x+y));
    else 
        st.insert((-(x-y-1) + x+1) % (x+y));

    cout << (st.size()*(x+y)) / 2 << '\n';
}