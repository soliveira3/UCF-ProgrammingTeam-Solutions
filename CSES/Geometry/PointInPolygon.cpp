#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
template <class T>
struct Point
{
    typedef Point pt;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(pt p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(pt p) const { return tie(x, y) == tie(p.x, p.y); }
    pt operator+(pt p) const { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
    pt operator*(T d) const { return pt(x * d, y * d); }
    pt operator/(T d) const { return pt(x / d, y / d); }
    T dot(pt p) const { return x * p.x + y * p.y; }
    T cross(pt p) const { return x * p.y - y * p.x; }
    T cross(pt a, pt b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x=axis in interval [=pi , pi ]
    double angle() const { return atan2(y, x); }
    pt unit() const { return *this / dist(); } // makes d i s t ()=1
    pt perp() const { return pt(-y, x); }       // rotates +90 degrees
    pt normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    pt rotate(double a) const { return pt(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
    friend istream &operator>>(istream &in, Point &p) { double x, y; in >> p.x >> p.y; return in; }
    friend ostream &operator<<(ostream &os, pt p) { return os << "(" << p.x << "," << p.y << ")"; }
};
 
 
typedef Point<ll> pt;
 
bool above(pt a, pt b)
{
    return b.y >= a.y;
}
 
 
int orient(pt p1, pt p2, pt p3)
{
    ll val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
 
    if (val == 0) return 0;
    else return ((val > 0) ? 1 : -1);
}
 
bool crossesRay(pt a, pt p, pt q)
{
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}
 
template<class pt> bool onSegment(pt s, pt e, pt p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
 
int inPolygon(vector<pt> p, pt a)
{
    ll numCrossings = 0;
 
    for (ll i = 0, n = p.size(); i < n; i++)
    {
        if (onSegment(p[i], p[(i+1)%n], a))
            return 2;
 
        numCrossings += crossesRay(a, p[i], p[(i+1) % n]);
 
    }
 
    return numCrossings & 1;
}
 
int main ()
{
 
    ll n, m;
    cin >> n >> m;
 
    vector<pt> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
 
    for (int i = 0; i < m; i++)
    {
        pt p;
        cin >> p.x >> p.y;
 
        int x = inPolygon(points, p);
 
        if (x == 2) cout << "BOUNDARY\n";
        else cout << ((x == 1) ? "INSIDE\n" : "OUTSIDE\n");
    }
 
	return 0;
}