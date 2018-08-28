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
const long long MAX = 1000 * 1000 * 10 + 5;
int n;
int x;
int a[50][50];

int main() {
	fast();
	cin >> n;
	if (n == 1){
		return cout << 1 << endl, 0;
	}
	x = n / 2;
	int cur = 1;
	int cnt = (n * n + 1) / 2;
	cnt -= (n + n - 1);
	cnt /= 4;
	for (int i = 1; i <= x&&cnt; i++){
		for (int j = 1; j <= x&&cnt; j++){
			if (i == j)continue;
			a[i][j] = cur; cur+=2;
			a[i][n - j + 1] = cur; cur += 2;
			a[n - i + 1][j] = cur; cur += 2;
			a[n - i + 1][n - j + 1] = cur; cur += 2;
			cnt--;
		}
	}
	int ev = 2;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!a[i][j] && (i != (n+1)/2) && j != (n+1)/2)cout << ev << " ", ev += 2;
			else if ((i == (n + 1) / 2) || j == (n + 1) / 2) cout <<cur << " " , cur+=2;
			else cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
