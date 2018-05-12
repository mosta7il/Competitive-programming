#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;

vector < pair<long double, int> >pts;
int get_quad(int x, int y){
	if (x >= 0 && y >= 0)
		return 0;
	if (x >= 0)
		return 3;
	if (x < 0 && y >= 0)
		return 1;
	return 2;
}
const long double PI = acos(-1);
long double get_angle(int x , int y){
	long double ang = atan2((long double)y*1.0, (long double)x*1.0);
	return ang;
}

int main() {
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		long double res = get_angle(x, y);
		while (res < 0) res += PI*2;
		pts.push_back({ res, i });

	}
	sort(pts.begin(), pts.end());

	long double mn = 8000000;
	pair<int, int> ans;

	for (int i = 0; i < pts.size(); i++){
		long double res = fabs(pts[(i + 1) % n].first - pts[i].first);
		while (res < 0)res += PI*2;
		if (res <= mn){
			ans = { pts[(i + 1) % n].second, pts[i].second };
			mn = res;
		}
		if (2*PI - res<=mn){
			ans = { pts[(i + 1) % n].second, pts[i].second };
			mn = 2*PI - res;;
		}
	}
	
	cout << ans.first +1<< " " << ans.second +1<< endl;
	return 0;
}
