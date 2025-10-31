#include <bits/stdc++.h>
using namespace std;

struct node {
    int end = 0;
    int best = 0;
    int dir = -1;
    vector<node*> children;
    node() {
        children = vector<node*>(26,nullptr);
    }

    int insert(string &s, int idx) {
        if(idx == s.size()) { end++; return end; }
        if(s[idx] == '*') {
            for(int i = 0; i < 26; i++) {
                if(!children[i]) children[i] = new node();
                int res = children[i]->insert(s,idx+1);
                if(best < res) {
                    best = res;
                    dir = i;
                } else if(best == res && i < dir) {
                    best = res;
                    dir = i;
                }
            }
        } else {
            if(!children[s[idx]-'a']) children[s[idx]-'a'] = new node();
            int res = children[s[idx]-'a']->insert(s,idx+1);
                if(best < res) {
                    best = res;
                    dir = s[idx]-'a';
                } else if(best == res && s[idx]-'a' < dir) {
                    best = res;
                    dir = s[idx]-'a';
                }
        }
        return best;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n,c;
    cin >> n >> c;
    node* trie = new node();
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie->insert(s,0);
    }

    string res = "";
    int best = trie->best;
    for(int i = 0; i < c; i++) {
        res += (char)('a'+trie->dir);
        trie = trie->children[trie->dir];
    }

    cout << res << ' ' << best << '\n';
}