#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;

int a[101][101];
int main(){
	int n, m, d;
	cin >> n >> m >> d;
	vector<int>v;
	for (int i = 0; i < n;i++)
	for (int j = 0; j < m; j++){
		cin >> a[i][j];
		v.push_back(a[i][j]);
	}
	int cnt = 0, mn = INT_MAX;
	bool f = 0;
	for (int w = 0; w < v.size(); w++){
		f = 0;
		cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				double x = abs(a[i][j] - v[w]) / (double)d;
				if (x == (int)x){
					cnt += x;
				}
				else{
					f = 1;
					j = m;
					i = n;
				}
			}
		}
			if (!f){
				mn = min(mn, cnt);
			}
	}

	if ( mn == INT_MAX){
		cout << -1;
	}
	else{
		cout << mn << endl;
	}
	return 0;
}
