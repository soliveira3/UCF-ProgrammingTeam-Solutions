#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define sz(x) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<ll> vll;

const ll mod = 1e9+7;

struct st { int len, pos, term; st *link; map<char, st*> next; };
st *suffixAutomaton(string &str) {
	st *last = new st(), *root = last;
	for(auto c : str) {
		st *p = last, *cur = last = new st{last->len + 1, last->len};
		while(p && !p->next.count(c))
			p->next[c] = cur, p = p->link;
		if (!p) cur->link = root;
		else {
			st *q = p->next[c];
			if (p->len + 1 == q->len) cur->link = q;
			else {
				st *clone = new st{p->len+1, q->pos, 0, q->link, q->next};
				for (; p && p->next[c] == q; p = p->link)
					p->next[c] = clone;
				q->link = cur->link = clone;
			}
		}
	}
	while(last) last->term = 1, last = last->link;
	return root;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	st* sa = suffixAutomaton(s);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int res = 1;
		st* cur = sa;
		for(char c: t) {
			st* nxt = cur;
			if(!cur->next.count(c)) {
				res++;
				nxt = sa;
			}
			if(!nxt->next.count(c)) {
				res = -1;
				break;
			}
			cur = nxt->next[c];
		}

		cout << res << '\n';
	}
}