#include<iostream>
#include<algorithm>
using namespace std;
void main(){
	int n, k, l, c, d, p, nl, np;

	cin >> n >> k >> l >> c >> d >> p >> nl >> np;

	int s, li, g;
	s = c*d;
	li = (l*k) / nl;
	g = p / np;

	int min1 = min(s, li);
	min1 = min(min1, g);

	cout << min1 / n;
}
