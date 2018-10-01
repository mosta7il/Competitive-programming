#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e17;
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
const long long MAX = 100 * 1000 + 5;
long long n, r;
int a[MAX];
bool lowestOverflow(double md){
	
	double rate = r * md;
	double rem = 0;
	for (int i = 0; i < n-1; i++){
		if (a[i] <= (rate + rem) ){
			rem += (rate - a[i]);
		}
		else{
			rem = 0;
		}
	}
	if ((rate + rem) >= a[n - 1])
		return 1;
	return 0;
}

bool fullOverflow(double md){
	double rate = r * md;
	double rem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] <= (rate + rem)){
			rem += (rate - a[i]);
		}
		else{
			return 0;
		}
	}
	return 1;
}
int main() {
	fast();
	while (cin >> n>>r){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		double lo = 0, hi = 1e11, ans = 0.0 , ans2 = 0.0;
		for (int i = 0; i < 300; i++){
			double md = (lo + hi) / 2;
			if (lowestOverflow(md)){
				hi = md - 0.1;
				ans = md;
			}
			else lo = md + 0.1;
		}

		lo = 0, hi = 1e11, ans2 = 0.0;
		for (int i = 0; i < 300; i++){
			double md = (lo + hi) / 2;
			if (fullOverflow(md)){
				hi = md - 0.1;
				ans2 = md;
			}
			else lo = md + 0.1;
		}
		cout << fixed << setprecision(6);
		cout << ans << " " << ans2 << "\n";
	}



	return  0;
}
