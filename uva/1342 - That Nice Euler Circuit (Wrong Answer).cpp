/*

*/

// Defualt Block
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define mod 1e9+7
#define EPS 1e-9
#define MLOG 30
#define MAX 1 * 100 * 1000+5

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

// Add any thing after that comment 


double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point {
	double x, y;  
	point() { x = y = 0.0; }                      
	point(double _x, double _y) : x(_x), y(_y) {} 

	bool operator < (point other) const { 
		if (fabs(x - other.x) > EPS)      
			return x < other.x;          
		return y < other.y;
	} 

	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
	point operator-(const point &a) const {
		return point(x - a.x, y - a.y);
	}
	point operator+(const point &a) const {
		return point(x + a.x, y + a.y);
	}
	point operator*(const double a) const {
		return point(x * a, y * a);
	}
};

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
	double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
	return point(p.x * cos(rad) - p.y * sin(rad),
		p.x * sin(rad) + p.y * cos(rad));
}

// distance between p1 and p2
double dist(point p1, point p2) {   						
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           


// Lines
struct line { double a, b, c; };          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {						 // vertical line is fine
		l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
	}
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {           // also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;            // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else                  p.y = -(l2.a * p.x + l2.c);
	return true;
}

struct vec {
	double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
	return vec(v.x * s, v.y * s);
}               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
	return point(p.x + v.x, p.y + v.y);
}

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line &l) {
	l.a = -m;                                               // always -m
	l.b = 1;                                                 // always 1
	l.c = -((l.a * p.x) + (l.b * p.y));
}                // compute this

void closestpoint(line l, point p, point &ans) {
	line perpendicular;         // perpendicular to l and pass through p
	if (fabs(l.b) < EPS) {              // special case 1: vertical line
		ans.x = -(l.c);   ans.y = p.y;      return;
	}

	if (fabs(l.a) < EPS) {            // special case 2: horizontal line
		ans.x = p.x;      ans.y = -(l.c);   return;
	}

	pointSlopeToLine(p, 1 / l.a, perpendicular);          // normal line
	// intersect line l with this perpendicular line
	// the intersection point is the closest point
	areIntersect(l, perpendicular, ans);
}

// returns the reflection of point on a line
void reflectionpoint(line l, point p, point &ans) {
	point b;
	closestpoint(l, p, b);                     // similar to distToLine
	vec v = toVec(p, b);                             // create a vector
	ans = translate(translate(p, v), v);
}         // translate p twice

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));                  // translate a to c
	return dist(p, c);
}           // Euclidean distance between p and c

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);                   // closer to a
		return dist(p, a);
	}         // Euclidean distance between p and a
	if (u > 1.0) {
		c = point(b.x, b.y);                   // closer to b
		return dist(p, b);
	}         // Euclidean distance between p and b
	return distToLine(p, a, b, c);
}          // run distToLine as above

double angle(point a, point o, point b) {  // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// segment - segment intersection
bool SegmentIntersection(point a1, point a2, point b1, point b2) {
	double c1 = cross(toVec(a1, a2), toVec(a1, b1) ),
		   c2 = cross(toVec(a1, a2), toVec(a1, b2)),
		   c3 = cross(toVec(b1, b2), toVec(b1, a1)),
		   c4 = cross(toVec(b1, b2), toVec(b1, a2));
	return (dcmp(c1, 0.0) * dcmp(c2 , 0.0)) < 0 && (dcmp(c3 , 0.0) * dcmp(c4,0.0)) < 0;
}

// Get intersection point of two seg.
point getIntersect(point a1, point a2, point b1, point b2) {
	vec u = toVec(b1 , a1);
	double t = cross(toVec(b1, b2), u) / cross(toVec(a1, a2), toVec(b1, b2));
	return a1 + (a2 - a1) * t;
}

// Is point P on segment a1--a2
bool OnSegment(point P, point a1, point a2) {
	return dcmp(cross(toVec(P, a1), toVec(P, a2)), 0.0) == 0 
		&& dcmp(dot(toVec(P, a1), toVec(P, a2) ), 0.0) < 0;
}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}


void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n;

int main(){
	fast();
	int cas = 1;
	while (cin >> n &&n){
		cout << "Case " << cas++ << ": There are ";
		vector< point > p;
		vector< pair < point, point > >seg;
			
		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			p.push_back(point(x, y));
		}
	
		for (int i = 1; i < n; i++){
			seg.push_back({ p[i - 1], p[i] });
		}
		int ans = 1;
		for (int i = 2; i < seg.size(); i++){
			vector< point >w;
			for (int j = i - 2; j >= 0; j--){
				if (SegmentIntersection(seg[i].first, seg[i].second, seg[j].first, seg[j].second)){
					w.push_back(getIntersect(seg[i].first, seg[i].second, seg[j].first, seg[j].second));
				}
				else if ((seg[j].first == seg[i].second )){
					w.push_back(seg[j].first);
				}
				else if (seg[j].second == seg[i].second){
					w.push_back(seg[j].second);
				}
			}
			sort(w.begin(), w.end());
			unique(w.begin(), w.end());
			ans += w.size();
		}

		cout << ans << " pieces.\n";
	}

	return 0;
}
