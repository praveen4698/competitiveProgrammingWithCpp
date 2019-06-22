#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
struct Point
{
    int x, y;
    Point(int _x=0,int _y=0) : x(_x),y(_y) {}
    Point(const pair<int,int> &p):Point(p.first,p.second) {}
    bool operator<(const Point &o)const{return o.x==x?y<o.y:x<o.x;}
    bool operator==(const Point &p)const{return x==p.x &&y==p.y;}
    Point operator-(const Point &o)const{return Point ( x-o.x,y-o.y );}
    Point operator+(const Point &o)const{return Point(x+o.x,y+o.y);}
    double norm()const{return sqrt(double(x)*double(x)+double(y)*double(y));}
    Point ortho(){return Point(y,-x );}
    void normalize()
    {
        double n=norm();
        if (!n) return;
        x/=n;
        y/=n;
    }

};
inline ll cross(const Point &a, const Point &b){return (ll)a.x*b.y-(ll)a.y*b.x;}
inline bool collinear(const Point &a,const Point &b,const Point&c ){ return !cross(a-b,a-c);}
inline bool ccw(const Point &a,const Point&b,const Point &c){ return cross(a-b,a-c)>0;} //return true to clockwise
vector<Point> convex_hull(vector<Point> &p)
{
    int n = (int)p.size();
    if (n < 2) return p;
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin());
    int cnt = 0;
    vector<Point> h(n*2);
    for (int i=0;i<n;h[cnt++]=p[i++])
        while (cnt>1 && !ccw(h[cnt-2],h[cnt-1],p[i]))
            --cnt;
    for (int i=n-2,t=cnt;i>=0;h[cnt++]=p[i--])
        while (cnt > t && !ccw(h[cnt-2], h[cnt-1],p[i]))
            --cnt;
    --cnt;
    if (cnt == 2 && h[0] == h[1]) --cnt;
    h.resize(cnt);
    return h;
}
ll twoArea(const vector<Point>& points)
{
    if(points.size()<3)return 0;
    ll res=0;
    for(int i=0;i<points.size()-1;++i)
        res+=cross(points[i],points[i+1]);
    res+=cross(points.back(),points[0]);
    return abs(res);
}
int main()
{
    return 0;
}



// Point having the least y coordinate, used for sorting other points
// according to polar angle about this point
Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point &a, Point &b, Point &c)
{
    int area = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    if (area > 0) return -1;
    else if (area < 0)return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int sqrDist(Point a, Point b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool polar_order(Point a, Point b)
{
    int order = ccw(pivot, a, b);
    if (order == 0) return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

vector<Point> grahamScan(vector<Point> &points)
{
    vector<Point> hull;
    int n = points.size();
    if (n < 3) return points;
    int leastY = 0;
    for (int i=1;i<n;i++)
        if(points[i] < points[leastY])
            leastY = i;
    swap(points[0],points[leastY]);
    pivot = points[0];
    sort(points.begin()+1,points.end(),polar_order);
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);
    for (int i=3;i<n;i++)
    {
        Point top = hull.back();
        hull.pop_back();
        while(ccw(hull.back(), top, points[i]) != -1)
        {
            top = hull.back();
            hull.pop_back();
        }
        hull.push_back(top);
        hull.push_back(points[i]);
    }
    return hull;
}

int main()  {
    vector<Point> points;
  //   = {{0, 0}, {1, 1}, {2, 2}, {3, -1}};
    points.push_back(Point(0,0));
    points.push_back(Point(1,1));
    points.push_back(Point(2,2));
    points.push_back(Point(3,-1));
    vector<Point> hull = grahamScan(points);
    for(auto p:hull)
    {


        printf("(%d, %d)\n", p.x, p.y);
    }

    return 0;
}
