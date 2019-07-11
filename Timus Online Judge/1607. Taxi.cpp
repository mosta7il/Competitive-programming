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
#define OO 2e9
#define EPS 1e-12
#define MLOG 20
#define MAX 1 * 100 * 1000+5
const int mod = 998244353;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);
#endif
	 
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
ll a, b, c, d;
int main(){
	fast();

	cin >> a >> b >> c >> d;

	int ans = -1;
	c += d;
	bool turn = 0;
	while (1){
		if (!turn){
			if (c - d <= a){
				ans = a;
				break;
			}
			c -= d;
		}
		else{
			if (a + b >= c){
				ans = c; break;
			}
			a += b;
		}
		turn = !turn;
	}
	cout << ans << endl;
	return 0;
}
