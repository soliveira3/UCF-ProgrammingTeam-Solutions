#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b);
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) {
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

struct SAQuery{
	SuffixArray sa; RMQ<int> lcp;
	string s; vector<int> sainv;
	SAQuery(SuffixArray sa,string s):sa(sa), lcp(sa.lcp), s(s){
		sainv.resize(sz(s)+1);
		rep(i,0,sz(sa.sa)) sainv[sa.sa[i]] = i;
	} 
	int len_lcp(int u, int v){
		if(u==v) return sz(s)-u;
		auto[l,r] = minmax(sainv[u],sainv[v]);
		return lcp.query(l+1,r+1);
	}
	int cmp_sub(int l1, int r1, int l2, int r2){ 
		auto sgn = [](int x){ return (x>0)-(x<0); };
		int len1 = r1-l1+1, len2 = r2-l2+1;
		return len_lcp(l1,l2) < min(len1,len2)
			? sgn(sainv[l1]-sainv[l2]): sgn(len1-len2);
	}
	pair<int, int> find_str(int s_l, int s_r) { 
		auto cmp = [&](int i, bool flip) -> bool {
			return flip ^ (len_lcp(i, s_l) < s_r - s_l); };
		auto it = begin(sa.sa) + sainv[s_l];
		int l=lower_bound(begin(sa.sa),it,0,cmp)-begin(sa.sa);
		int r=lower_bound(it+1,end(sa.sa),1,cmp)-begin(sa.sa);
		return {l, r};
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int d;
    cin >> s >> d;
    SuffixArray sa(s);
    SAQuery sq(sa, s);
    int res = 0;

    for(int i = 0; i < sz(s); i++) {
        int amt = 0;
        for(int j = 1; j <= d; j++) {
            if(i+j-1 >= sz(s))break;
            int match = sq.len_lcp(i,i+j);
            amt = max(amt, j+match);
        }
        res++;
        i += amt - 1;
    }

    cout << res << '\n';
}