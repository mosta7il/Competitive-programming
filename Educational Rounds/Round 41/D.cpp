#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

typedef complex<long double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;

int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 5 * 100 * 1000 + 5;
int n;
long long x[100005], y[100005];

bool isCollinear(int a, int b, int c)
{
	return (x[a] * (y[b] - y[c]) + x[b] * (y[c] - y[a]) + x[c] * (y[a] - y[b]) == 0);
}

bool secondL(vector< int> v){
	if (v.size() < 3)
		return 1;
	for (int i = 2; i < v.size(); i++){
		if (!isCollinear(v[i-2], v[i-1], v[i])){
			return 0;
		}
	}
	return 1;
}
bool firstL(int a, int b){
	vector<int >sec;
	for (int i = 0; i < n; i++){
		if (i == a || i == b)continue;
		if (!isCollinear(i,a , b)){
			sec.push_back(i);
		}
	}
	return secondL(sec);
}
int main() {
	fast();
	cin >> n;

	for (int i = 0; i < n; i++){
		int xx, yy; cin >> xx >> yy;
		x[i] = xx, y[i] = yy;
	}

	if (n < 3 || n == 4){
		cout << "YES\n";
		return 0;
	}
	if (firstL(0, 1) || firstL(0, 2) || firstL(1, 2))
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
