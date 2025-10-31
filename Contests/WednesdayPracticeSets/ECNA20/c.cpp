#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, string> haveToWant, wantToHave, nxt;
    map<string, int> indeg, outdeg;
    set<string> uni;
    while (n--) {
        string _, a, b; cin >> _ >> a >> b;
        haveToWant[a] = b;
        wantToHave[b] = a;
        uni.insert(a);
        uni.insert(b);
    }

    
    for (auto &s : uni) {
        if (wantToHave.count(s)) {
            nxt[s] = wantToHave[s];
            outdeg[s]++;
            indeg[wantToHave[s]]++;
        }
    }
    int best = 0;
    set<string> good = uni;
    for (auto s : uni) {
        if (indeg[s] == 1) continue;
        while (s != "") {
            good.erase(s);
            s = nxt.count(s) ? nxt[s] : "";
        }
    }

    set<string> vis;
    for (auto s : good) {
        int res = 0;
        while (!vis.count(s)) {
            vis.insert(s);
            res++;
            s = nxt[s];
        } 
        best = max(best, res);
    }

    if (!best) cout << "No trades possible\n";
    else cout << best << "\n";

}