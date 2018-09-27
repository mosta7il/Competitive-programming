#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef complex<long double> point;

#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 500 * 1000 + 5;

int n, p;

int XX[MAX], YY[MAX];

bool pointOnLine(const point& a, const point& b, const point& p){
	return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}
int main() {
	fast();

	cin >> n >> p;
	for (int i = 0; i < n; i++){
		cin >> XX[i] >> YY[i];
	}
	if (n <= 2){
		cout << "possible\n";
		return 0;
	}

	for (int i = 0; i < 500; i++){
		int l = (rand() * rand()) % n, r = (rand() * rand()) % n;
		while (l == r){
			l = (rand() * rand()) % n;
			r = (rand() * rand()) % n;
		}
		int cnt = 2;
		for (int j = 0; j < n; j++){
			if (j == l || j == r)
				continue;
			if (pointOnLine(point(XX[l], YY[l]), point(XX[r], YY[r]), point(XX[j], YY[j])))
				cnt++;
		}
		if (cnt * 100 >= n * p){
			cout << "possible\n";
			return 0;
		}
	}
	cout << "impossible\n";
	return  0;
}
