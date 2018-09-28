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

const  long long  OO = 1e17;
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
const long long MAX = 1000 * 1000 * 10 + 5;
int n;
long long s, t;
multiset< int > ms;
long long ans[MAX];

bool vis[MAX];
int a[2001];

long long gcd(long long a, long long b){
	if (!b)
		return a;
	return gcd(b, a%b);
}
int main() {
	fast();
	cin >> n >> s >> t;

	for (int i = 0; i < n; i++){
		int x; cin >> a[i];
		ms.insert(a[i]);
	}

	for (int i = 0; i < n; i++){
		if (vis[a[i]])continue;
		vis[a[i]] = 1;
		multiset<int>tmp = ms;
		auto ii = tmp.lower_bound(a[i]);
		int curIdx = (*ii);
		long long cost = 0;
		tmp.erase(ii);
		curIdx += t;
		curIdx %= s;
		
			cost += t;
		while (tmp.size()){
			
			auto it = tmp.lower_bound(curIdx);
			if (it == tmp.end()){
				cost += s - abs(curIdx - (*tmp.begin()));
				curIdx = (*tmp.begin()) + t;
				curIdx %= s;
				tmp.erase(tmp.begin());
			}
			else{
				cost += ((*it) - curIdx);
				curIdx = (*it) + t;
				curIdx %= s;
				tmp.erase(it);
			}
				cost += t;
		}
		ans[a[i]] = cost;
	}
	long long mn = OO, mx = -1;
	long long sum = 0;
	for (int i = 0; i < s; i++){
		if (ms.find(i) != ms.end()){
			mx = max(mx, ans[i]);
			mn = min(mn, ans[i]);
			sum += ans[i];
		}
		else{
			auto ii = ms.upper_bound(i);
			if (ii == ms.end()){
				int dist = s - (abs(i - (*ms.begin())));
				mn = min(mn, ans[(*ms.begin())]+dist);
				mx = max(mx, ans[(*ms.begin())]+dist);
				sum += ans[(*ms.begin())] + dist;
			}
			else{
				int dist = (*ii) - i;
				mn = min(mn, ans[(*ii)] + dist);
				mx = max(mx, ans[(*ii)] + dist);
				sum += ans[(*ii)] + dist;
			}
		}
	}

	cout << mn << endl;
	cout << mx << endl;
	long long g = gcd(sum, s);
	cout << sum / g << "/" << s / g << endl;
	return  0;
}
