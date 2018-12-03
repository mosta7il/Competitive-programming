/*
	- Solution =
			Sum { floor ( n /i ) * i , 1 <= i <= n } - [ n - ( n * ( n + 1 ) ) / 2 ]

*/

// Defualt Block
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
#define mod 1e9+7
#define EPS 1e-8
#define MLOG 30
#define MAX 10 * 100 * 1000+5

int dcmp(long double x, long double y){
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
// Add any thing after that comment 

int n;
long long ans;

long long SumFromAToB(int l, int r){

	return (0ll + l + r) * (1ll + r - l) / 2;
}
int main(){
	fast();
	int cas = 1;
	while (cin >> n&&n){
		cout << "Case " << cas++ << ": ";
		ans = 0;
		ans -= n - 1;
		ans -= (SumFromAToB(1, n));
		for (int i = 1; i <= n; i++){
			int x = n / (n / i);
			ans += SumFromAToB(i, x) * 1ll * (n / i);
			i = x;
		}
		cout << ans << endl;
	}

	return 0;
}
