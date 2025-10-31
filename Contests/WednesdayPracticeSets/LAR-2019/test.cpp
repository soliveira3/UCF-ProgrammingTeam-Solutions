const int ABSIZE = 26;

struct node {
    int nxt[ABSIZE];
    vi ids = {};
    int prv = -1, link = -1;
    char c;
    int linkMemo[ABSIZE];

    node(int prv = -1, char c = '$'): prv(prv), c(c) {
        fill(all(nxt), -1);
        fill(all(linkMemo), -1);
    }
};

vector<node> trie(1);

void addWord(string &s, int id) {
    int cur = 0;
    for(char c: s) {
        int idx = c - 'A';
        if(trie[cur].nxt[idx] == -1) {
            trie[cur].nxt[idx] = sz(trie);
            trie.emplace_back(cur, c);
        }
        cur = trie[cur].nxt[idx];
    }
    trie[cur].ids.push_back(id);
}

int getLink(int cur);

int calc(int cur, char c) {
    int idx = c - 'A';
    auto &ret = trie[cur].linkMemo[idx];
    if(ret != -1) return ret;
    if(trie[cur].nxt[idx] != -1)
        return ret = trie[cur].nxt[idx];
    return ret = cur == 0 ? 0 : calc(getLink(cur), c);
}

int getLink(int cur) {
    auto &ret = trie[cur].link;
    if(ret != -1) return ret;
    if(cur == 0 || trie[cur].prv == 0) return ret = 0;
    return ret = calc(getLink(trie[cur].prv), trie[cur].c);
}