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
int n;
char r;
int main() {
	fast();
	while (cin >> n>>r){
		if (r == 'B' || r == 'R'){
			cout << n << "\n";
		}
		else if (r == 'K'){
			if (n == 1)cout << "1\n";
			else cout << "4\n";
		}
		else if (r == 'N'){
			if (n <= 2)cout << 1 << "\n";
			else cout << "2\n";
		}
	}


	return  0;
}
