#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long long MAX = 2 * 1000 + 1;
long long a, b, c;
int main(){
	fast();
	int cnt = 0;
	cin >> cnt;
	while (cnt--){
		cin >> a >> b >> c;
		int sqr = sqrt(c * 1.0);
		long long tmpx = OO, tmpy = 0, tmpz = 0;
		bool f = 0;
		for (long long x = -sqr; x <= sqr; x++){
			for (long long y = -sqr; y <= sqr; y++){
				long long z = a - (y + x);
				bool ok = (x != y && x != z && y != z);
				if (x * y * z == b && (x*x + y*y + z*z) == c&&ok){
					f = 1;
					if (tmpx > x){ tmpx = x, tmpy = y, tmpz = z; }
					else if (tmpx == x && tmpy > y){ tmpx = x, tmpy = y, tmpz = z; }
				}
			}
		}

		if (!f){ cout << "No solution.\n"; }
		else cout << tmpx << " " << tmpy << " " << tmpz << endl;
	}
	return 0;
}
