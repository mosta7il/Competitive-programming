/*
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
#define MAX  2* 100  * 1000+5
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
int n, m, x;
int main(){
	fast();

	cout << fixed << setprecision(5);
	while (cin >> m >> n >> x){
		int yes = (n * (n - 1)) + (m * n);
		int no = (m * (m - x - 1)) + (n * (m - x));
		cout << (yes * 1.0) / (yes + no) << endl;
	}
	return 0;
}
