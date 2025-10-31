#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = a; i < (ll)(b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef vector<ll> vll;
using ld = long double;

const long double EPS = 1e-7;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrt((ld)dist2()); }
	ld angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); }
	P perp() const { return P(-y, x); }
	P normal() const { return perp().unit(); }
	P rotate(ld a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};


typedef Point<ld> P;
ld segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max((ld).0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> bool onSegment(P s, P e, P p) {
	return segDist(s,e,p)<=EPS;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

using namespace std::chrono;
int main() {
    auto t1 = steady_clock::now();
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<array<P,2>> guys(n);
    for(int i = 0; i < n; i++) {
        cin >> guys[i][0].x >> guys[i][0].y >> guys[i][1].x >> guys[i][1].y;
    }
    ld xs,ys,vs;
    cin >> xs >> ys >> vs;
    P myStart(xs,ys);
    
    int startIs = 0;
    for(int i = 0; i < n; i++) startIs = guys[i][0] == myStart || guys[i][1] == myStart;


    int curCnt = 0;
    for(int i = 0; curCnt < n; curCnt++, i++) {
        if(startIs)continue;
        if(!onSegment(guys[i][0], guys[i][1], myStart))continue;
        vector<P> tmp = {guys[i][0], guys[i][1], myStart};
        sort(tmp.begin(), tmp.end(), [&](P p, P q) {
            P v = guys[i][1] - guys[i][0];
            return v.dot(p - guys[i][0]) < v.dot(q - guys[i][0]);
        });
        guys.push_back({tmp[0],tmp[1]});
        guys.push_back({tmp[1],tmp[2]});
        guys.erase(guys.begin()+i);
        --i;
    }
    
    ld x1f, y1f, x2f, y2f, vf;
    cin >> x1f >> y1f >> x2f >> y2f >> vf;
    P bumStart(x1f, y1f);
    P bumEnd(x2f, y2f);
    
    vector<P> intersections;
    n = sz(guys);
    curCnt = 0;
    for(int i = 0; curCnt < n; curCnt++, i++) {
        auto inter = segInter(bumStart,bumEnd,guys[i][0], guys[i][1]);
        if(inter.size() != 1)continue;
        intersections.push_back(inter[0]);
        vector<P> tmp = {guys[i][0], guys[i][1], inter[0]};
        sort(tmp.begin(), tmp.end(), [&](P p, P q) {
            P v = guys[i][1] - guys[i][0];
            return v.dot(p - guys[i][0]) < v.dot(q - guys[i][0]);
        });
        guys.push_back({tmp[0],tmp[1]});
        guys.push_back({tmp[1],tmp[2]});
        guys.erase(guys.begin()+i);
        --i;
    }

    vector<array<P, 2>> other = guys;
    n = sz(other);

    map<int, vector<P>> ints;

    for (int i = 0; i < n; i++) {
        ints[i].push_back(other[i][0]);
        ints[i].push_back(other[i][1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto inter = segInter(other[i][0], other[i][1], other[j][0], other[j][1]);
            if(inter.size() != 1) continue;
            ints[i].push_back(inter[0]);
            ints[j].push_back(inter[0]);
        }
    }

    guys.clear(); 
    for (int i = 0; i < n; i++) {        
        P v = other[i][1] - other[i][0];
        sort(all(ints[i]), [&](P p, P q) {
            return v.dot(p - other[i][0]) < v.dot(q - other[i][0]);
        });

        ints[i].erase(unique(all(ints[i])), ints[i].end());

        for (int j = 0; j < ints[i].size(); ++j) {
            if (ints[i][j] == ints[i][j+1]) continue;
            guys.push_back({ints[i][j], ints[i][j + 1]});
        }
    }

    vector<vector<pair<ld,int>>> g;
    map<P, int> idx;
    int cnt = 0;
    for(int i = 0; i < sz(guys); i++) {
        if(!idx.count(guys[i][0])) idx[guys[i][0]] = cnt++, g.push_back({});
        if(!idx.count(guys[i][1])) idx[guys[i][1]] = cnt++, g.push_back({});
        g[idx[guys[i][0]]].push_back({(guys[i][0]-guys[i][1]).dist(), idx[guys[i][1]]});
        g[idx[guys[i][1]]].push_back({(guys[i][0]-guys[i][1]).dist(), idx[guys[i][0]]});
    }

    ld INF = 1e15;
    priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> pq;
    vector<ld> dist(cnt+1,INF);
    dist[idx[myStart]] = 0;
    pq.emplace(0,idx[myStart]);
    while(!pq.empty()){
        auto[cost,u] = pq.top(); pq.pop();
        if(cost > dist[u]) continue;
        for(auto[w, v]: g[u]){
            if(cost+w < dist[v]){
                dist[v] = cost+w;
                pq.emplace(cost+w,v);
            }
        }
    }
    
    sort(intersections.begin(), intersections.end(), [&](P p, P q) {
        P v = bumEnd - bumStart;
        return v.dot(p - bumStart) < v.dot(q - bumStart);
    });
    
    ld best = 1e18;
    for(int i = 0; i < intersections.size(); i++) {
        ld myTime = dist[idx[intersections[i]]] / (ld) vs;
        ld yourTime = (bumStart - intersections[i]).dist() / (ld) vf;
        if(myTime - yourTime <= EPS) {
            best = min(best, yourTime);
        }
    }
    if(best == 1e18) cout << -1 << '\n';
    else cout << best << '\n';
}