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
const long long MAX = 2 * 1000 + 5;
int n;
int a[MAX];
int main() {
	fast();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		if (n <= 2){
			cout << 1 << "\n";
			continue;
		}
		int dif = a[1] - a[0];
		int idx = 0;
		for (int i = 2; i < n; i++){
			if (dif != (a[i] - a[i - 1])){
				dif = (a[i] - a[i - 1]);
				idx = i - 1;
			}
		}
		cout << idx  + 1 << "\n";
	}



	return  0;
}
