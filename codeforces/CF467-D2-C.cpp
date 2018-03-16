#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<queue>

using namespace std;
int n, m, k;
long long a[5001];
long long *dp[5001];
long long fun(int i, int k){
	if (k == 0) return 0;
	if (i > n - m){
		if (k > 0)
			return (long long)(-10e9);
		else
			return 0;
	}
	if (dp[i][k] != -1) return dp[i][k];

	
	return dp[i][k] = max(fun(i + m, k - 1) + a[i + m] - a[i], fun(i + 1, k));
}

int main(){

	cin >> n >> m >> k;
	
	for (int i = 0; i < n ; i++){
		dp[i] = new long long[k+1];
	}
	a[0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= k; j++)
			dp[i][j] = -1;
	}

	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[i] = a[i - 1] + x;
	}


	cout << fun(0, k) << endl;
	return 0;
}
