#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

const long long OO = 1e9;
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
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 10* 100 * 1000 + 5;


int n, k;
string s, w;

int main() {
	fast();
	cin >> n >> k;
	cin >> s;
	w = s;

	for (int i = 0; i < n&&k; i++){
		int l = abs(s[i] - 'z');
		l = min(l, k);
		int r = abs(s[i] - 'a');
		r = min(r, k);
		if (l >= r){
			w[i] = s[i] + l;
		}
		else{
			w[i] = s[i] - r;
		}
		k -= max(l, r);
	}
	if (k)
		cout << -1 ;
	else cout << w;

	return 0;
}
