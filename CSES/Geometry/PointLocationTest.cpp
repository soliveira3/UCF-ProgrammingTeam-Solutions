#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
typedef struct P {
    ll x, y;
} Point;
 
 
ll orientation (Point p1, Point p2, Point p3)
{
    ll val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
 
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}
 
int main ()
{
	ll tc = 1;
	cin >> tc;
	for (ll i = 0; i < tc; i++)
    {
        vector<Point> points(3);
        for (ll j = 0; j < 3; j++)
            cin >> points[j].x >> points[j].y;
 
 
        ll o = orientation(points[0], points[1], points[2]);
 
        if (o == 0) cout << "TOUCH\n";
        else cout << ((o > 0) ? "RIGHT\n" : "LEFT\n");
    }
 
	return 0;
}

