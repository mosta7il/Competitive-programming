/*
	Let's define :
		pre[i] = sum	{ a[j] , 1 <= j <= n } ;
		mnR[i] = minmum { pre[j]  - pre[i-1] , i <= j <= n } ;
		mnL[i] = minmun { pre[j] , 1 <= j < i } ;
		
	Position i is a valid start if :
		1 - mnR[i] >=0 , and
		2 - pre[n] - pre[i - 1] + mnL[i] >= 0
	
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
int pre[MAX] , mnR[MAX], mnL[MAX];

int main(){
	fast();
	
	while (cin >> n&&n){

		int mn = mod;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			pre[i] = x + pre[i - 1];
			mnL[i] = mn;
			mn = min(mn, pre[i]);
		}

		mn = mod;
		mnR[n + 1] = mod + mod;
		for (int i = n; i >= 1; i--){
			int x = pre[i] - pre[i - 1];
			mnR[i] = min(mnR[i+1] + x , x);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++){
			int sum = pre[n] - pre[i - 1] + mnL[i];
			if (mnR[i] >= 0&& sum>=0){
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
