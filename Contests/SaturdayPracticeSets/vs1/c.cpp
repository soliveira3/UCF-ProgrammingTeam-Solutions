#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (int)b; i++)
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;




template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point
{
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    typedef Point<T> P;
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+ (P p) const { return P(x+p.x, y+p.y); }
    P operator- (P p) const { return P(x-p.x, y-p.y); }
    P operator* (T d) const { return P(x*d, y*d); }
    P operator/ (T d) const { return P(x/d, y/d); }

    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross (P a, P b) const { return (a-*this).cross(b-*this); }
    P perp() const {return P(-y, x); }

    ld dist2() const { return x*x + y*y; }
    ld dist() const { return sqrt((ld)dist2()); }
    
};

typedef Point<ld> P;
struct seg { P s, e; };

ld eps = 1e-8;
P start, endP;
ll n;


ld pointSegDist(P &s, P &e, P &p)
{
    if (s == e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d, max((ld)0.0, (p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

bool onSegment(P s, P e, P p) { return p.cross(s, e) == 0 && (s-p).dot(e-p) <= 0; }

vector<P> segInter(P a, P b, P c, P d)
{
    auto oa = c.cross(d, a), ob = c.cross(d, b),
         oc = a.cross(b, c), od = a.cross(b, d);

    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a*ob-b*oa) / (ob - oa)};

    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {all(s)};
}

P lineProj (P a, P b, P p, bool refl = false)
{ P v = b-a; return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2(); }


ld findRes(ll mask, vector<seg> segs)
{
    if (!(mask & 1) || !(mask & (n+1))) return 1e18;
    
    ld dist = 0;
    vll prevOn(n+2, 0), nextOn(n+2, 0);
    rep (i, 1, n+2)
    {
        if (mask & (i-1)) prevOn[i] = i-1;
        else prevOn[i] = prevOn[i-1];
    }

    for (int i = n; i > 0; i--)
    {
        if (mask & (i+1)) nextOn[i] = i+1;
        else nextOn[i] = nextOn[i+1];
    }
    
    bool possible = true;

    // going through mask
    rep (i, 1, n+1) {
    if (mask & (1 << i))
    {
        ld addDist = pointSegDist(segs[i].s, segs[i].e, interP);
        dist += addDist;
        P curInter;
        
        // reseting prevIntersection Point
        P ss = segs[i].s, se = segs[i].e;
        if (eps > abs(addDist - ((interP.x-ss.x)*(interP.x-ss.x) + (interP.y-ss.y)*(interP.y-ss.y))))
            curInter = ss;
        else if (eps > abs(addDist - ((interP.x-se.x)*(interP.x-se.x) + (interP.y-se.y)*(interP.y-se.y))))
            curInter = se;
        else
            curInter = lineProj(segs[i].s, segs[i].e, interP);
        
        // Check all intersection
        for (int j = prevSeg; j < i; j++)
            if (sz(segInter(interP, curInter, segs[i].s, segs[i].e)) == 0)
                possible = false;

        prevSeg = i+1;
        interP = curInter;
    }} 


    if (possible) cout << "\n" << dist << '\n';
    cout << '\n';

    return (possible) ? dist : 1e18;
}



int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    vector<seg> segs(n+2);
    cin >> segs[0].s.x >> segs[0].s.y;
    rep (i, 1, n+1) cin >> segs[i].s.x >> segs[i].s.y >> segs[i].e.x >> segs[i].e.y;
    cin >> segs[n+1].s.x >> segs[n+1].s.y;

    segs[0].e = segs[0].s;
    segs[n+1].e = segs[n+1].s;

    // For each subset
    ld minDist = 1e18;
    rep (mask, 1, (1 << n+2))
        minDist = min(minDist, findRes(mask, segs));

    cout << fixed << setprecision(12);
    cout << minDist << '\n';
}