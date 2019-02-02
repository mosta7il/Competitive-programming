/*
	p = probability of choose a man to give him a candy
	  = m / (m+w)
    q = probability of choose a women 
	  = 1 - p

	probability of choose even number of men = 
		probability of choose exactly zero men + 
		probability of choose exactly 2 men + ..... and so far as the number of men <= C.

	probability of choose exactly X men out of C choices = ( C choose X ) * ( p ^ X ) * ( q ^ (C-X) ).

	
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
double NCK[105][105];


double fast_power(double a, int b){
	if (!b)return 1;
	if (b == 1)return a;

	double ret = fast_power(a, b / 2);
	return ret * ret * fast_power(a, b % 2);
}
int m, w, c;

int main(){
	fast();
	for (int i = 0; i < 105; i++){
		NCK[i][0] = 1;
	}
	for (int i = 1; i < 105; i++){
		for (int k = 1; k <= i; k++){
			NCK[i][k] = NCK[i-1][k] + NCK[i - 1][k - 1];
		}
	}

	cout << fixed << setprecision(7);

	while (cin >> m >> w >> c ){
		if (!m && !w)break;
		double p = (m + 0.0) / (m + w),
			q = 1 - p;
		double ans = 0.0;
		for (int i = 0; i <= c; i+=2){
			ans += NCK[c][i] * fast_power(p, i) * fast_power(q, c - i);
		}
		cout << ans << endl;
	}
	return 0;
}
