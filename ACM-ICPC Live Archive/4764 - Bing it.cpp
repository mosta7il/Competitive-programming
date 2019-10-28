/*


*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e17
#define EPS 1e-12
#define MLOG 20
#define MAX 10 * 100 * 100+5
const int mod = 1e9 + 3;
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);
#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n, cas;
int lst[MAX], nxt[MAX], a[MAX];
int dp[MAX], vis[MAX];

int rec(int idx){
	if (idx >= n){
		return 0;
	}
	
	int &ret = dp[idx];
	if (vis[idx] == cas)
		return ret;

	vis[idx] = cas;
	ret = -1e9;
	ret = max(ret, rec(idx + 1));
	if (nxt[idx] != -1)
		ret = max(ret, rec(nxt[idx]) + (a[idx] == 999 ? 3 : 1));
	return ret;
}
int main(){
	fast();
	while (scanf("%d", &n) && n){
		cas++;
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			lst[a[i]] = -1;
		}
		
		for (int i = n; i > 0; i--){
			nxt[i] = lst[a[i]];
			lst[a[i]] = i;
		}
		printf("%d\n" ,rec(1));
	}

	return 0;

}
