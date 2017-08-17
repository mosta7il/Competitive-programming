#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

char a[1001][1001]; 
int n, m , x,y;
int  c[1001], t; int dp[1001][3][1001];
void co(){
	int cnt = 0;
	for (int i = 0; i < m; i++){
		cnt = 0;
		for (int j = 0; j < n; j++){
			if (a[j][i] == '#'){
				cnt++;
			}
		}
		c[i] = cnt; 
	}
}
long long rec(int i, int l , int w){
	if (i == m){
		if (w < x||w>y)return oo;
		else return 0;
	}
	if (dp[i][l][w] != -1)return dp[i][l][w];
	long long ret = oo;
	if (l == 2){
		ret = min(ret , rec(i + 1, 0, 1) + c[i]);
		ret = min(ret, rec(i + 1, 1, 1) + abs(n - c[i]));
	}
	if (l == 0){
		if (w+1 <= y)
			ret = min(ret, rec(i + 1, 0, w + 1) + c[i]);
		if (w>=x)
			ret = min(ret, rec(i + 1, 1, 1) + abs(n - c[i]));
	}
	if (l == 1){
		if (w>=x)
			ret = min(ret, rec(i + 1, 0, 1) + c[i]);
		if (w +1<=y)
			ret = min(ret, rec(i + 1, 1, w + 1) + abs(n - c[i]));
	}
	
	return dp[i][l][w] = ret;
}
int main(){
	fast();
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n;i++)
	for (int j = 0; j < m; j++)
		cin >> a[i][j];
	co();
	cout << rec(0, 2, 0) << endl;
	return 0;
}
//mosta7il_
