/*
  -- for each calculate :
       ** calculate the sector area = R * Theta / 2
              *** Alpha = Theata / 2;
       ** calcualate triangle area = R * R * cos(Alpha) * sin(Alpha)
       ** Answer = SectorArea - triangleArea
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-15);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 10 * 100 * 1000 + 5;

long long x, y, xx, yy, r, rr;

long double solve(long double dist, long double rad1 , long double rad2){
	long double rad1s = rad1 * rad1, rad2s = rad2*rad2, dists = dist * dist;
	long double alpha = acos((rad1s - rad2s + dists) / (2.0 * dist * rad1));
	long double sectorArea = rad1s * alpha;
	long double triangleArea = rad1s * cos(alpha) * sin(alpha);
	return sectorArea - triangleArea;
}
int main(){
	fast();
	cin >> x >> y >> r;
	cin >> xx >> yy >> rr;

	cout << fixed << setprecision(7);
	long double dist = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
	if (dcmp(dist, 0.0 + r + rr) == 1){
		cout << 0.0 << endl;
		return 0;
	}

	if (r < rr){
		swap(r, rr);
		swap(x, xx);
		swap(y, yy);
	}
	if (dcmp(dist + rr, r) <= 0){
		cout << rr * rr * PI << endl;
		return 0;
	}

	cout << solve(dist, r, rr) + solve(dist, rr, r) << endl;
	return 0;
}
