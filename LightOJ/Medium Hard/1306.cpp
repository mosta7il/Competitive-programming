/*
	- Transform Equation from Ax + By + C = 0  into Ax + By = C.
	- we can get one solution using extended eculidean iff gcd(A,B) | C.
	- to get all soultions :
		- compute lx1 , rx1 where :
		  lx1 : x of a solution (x , y) where x >= min_x and x is minimum.
		  rx1 : x of a solution (x , y) where x <= max_x and x is maximum.
		  
		- compute lx2 , rx2 where :
		  lx2 : x of a solution (x , y) where y >= min_y and y is minimum.
		  rx2 : x of a soultion (x , y) where y <= max_y and y is maximum.
		
		 - answer is the intersection between [lx1 - rx1] and [lx2 - rx2].
*/

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
#define EPS 1e-12
#define MLOG 20
#define MAX  3 * 100  * 1000+5
const ll mod = 1e9 + 7;

ll dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);
#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

ll check(ll b, ll c, ll y, ll yy, ll x, ll xx){
	if (c / b >= y && c / b <= yy)
		return (xx - x + 1);
	return 0;
}

// Ax + By = gcd(A , B);
ll extended_gcd(ll a, ll b, ll & x, ll & y) {
	if (a < 0){
		ll g = extended_gcd(-a, b, x, y);
		x = -x;
		return g;
	}
	if (b < 0){
		ll g = extended_gcd(a, -b, x, y);
		y = -y;
		return g;
	}
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll d = extended_gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

// find number of solutions
ll all_dioph_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
	ll x, y, g;
	g = extended_gcd(a, b, x, y);

	if (g && c%g == 0){
		x *= c / g;
		y *= c / g;
	}
	if (g && c%g)			return 0;

	if (!a && b)			return  check(b, c, miny, maxy, minx, maxx);

	if (a && !b)		    return check(a, c, minx, maxx, miny, maxy);

	if (!a && !b && c)		return 0;

	if (!a && !b && !c)		return (1ll * maxx - minx + 1) * (maxy - miny + 1);

	a /= g;  b /= g;

	ll sign_a = a>0 ? +1 : -1;
	ll sign_b = b>0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	ll lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	ll rx1 = x;

	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	ll lx2 = x;

	shift_solution(x, y, a, b, -(maxy - y) / a);
	ll rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);

	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);

	if (lx > rx) return 0;
	return (rx - lx) / abs(b) + 1;
}

ll t, cnt;


int main(){
	fast();
	cnt = 1;
	cin >> t;
	while (t--){
		cout << "Case " << cnt++ << ": ";
		ll a, b, c, x1, x2, y1, y2;
		cin >> a >> b >> c;
		cin >> x1 >> x2;
		cin >> y1 >> y2;
		c = -c;

		ll ans = all_dioph_solutions(a, b, c, x1, x2, y1, y2);
		cout << ans << endl;
	}
	return 0;
}
