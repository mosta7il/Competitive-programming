/*
  Ax + By = C 
  This is a linear Diaoph. equation
  could be solved using extended ecluidean algo.

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
const ll mod = 1e9+7;

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

// find one solution
bool dioph(ll a, ll b, ll c, ll &x, ll &y, ll &g){
	g = extended_gcd(a, b, x, y);

	if (g && c%g == 0){
		x *= c / g;
		y *= c / g;
		return 1;
	}
	return 0;
}
void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

int cnt, t;
ll a, b, c;
int main(){
	fast();
	cnt = 1;
	cin >> t;
	while (t--){
		
		cin >> a >> b >> c;
		ll x, y , g;
		g = extended_gcd(a, b, x, y);
		g = extended_gcd(g, c, x, y);
		a /= g, b /= g, c /= g;
		if (dioph(a, b, c, x, y, g)){
			a /= g;  b /= g;
			ll sign_a = a>0 ? +1 : -1;
			ll sign_b = b>0 ? +1 : -1;

			shift_solution(x, y, a, b, (1 - x) / b);
			if (x < 1)
				shift_solution(x, y, a, b, sign_b);
			cout << x << " " << y << endl;
		}
		else cout << "Error\n";
		
	}
	return 0;
} 
