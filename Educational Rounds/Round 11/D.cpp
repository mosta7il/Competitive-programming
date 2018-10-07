#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e9;
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
}

const long long MAX = 3 * 100 * 1000 + 5;

int n, m;
map <pair<long long , long long> , long long>mp;
int X[MAX], Y[MAX];
int main() {
	fast();
  /// the diagonals of a parallelogram split each other in the middle.
  /// count middles.
  
  
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			long long xx = X[i] + X[j], yy = Y[i] + Y[j];
			mp[{xx, yy}]++;
		}
	}
	long long ans = 0;
	for (auto e : mp){
		ans += e.second * (e.second - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}
