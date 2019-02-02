/*
	** The chance of the Ith player to win is 

		- the chance of winning in his first try + 
		  the chance of winning in his second try + ..... + to infinity.

	** the problem requires four digits of precision, you can just keep adding terms 
	   until the amount that you would add is too small to make a difference.
	
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
int t;
int n, idx;

double fast_power(double a, int b){
	if (!b)return 1.0;
	if (b == 1)return a;

	double ret = fast_power(a, b / 2);
	return ret * ret * fast_power(a, b % 2);
}
int main(){
	fast();
	cin >> t;

	cout << fixed << setprecision(4);
	while (t--){
		double p;
		cin >> n >> p >> idx;
		double pwr = fast_power(1 - p, idx - 1);
		double pwr2 = fast_power(1 - p, n);
		double x = pwr2;
		double ans = p * pwr ;
		for (int i = 0; i < 100000; i++){
			ans += p * pwr * pwr2;
			pwr2 *= x;
		}
		
		cout << ans << endl;
	}
	return 0;
}
