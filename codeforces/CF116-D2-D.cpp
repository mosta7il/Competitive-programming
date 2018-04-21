#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e6;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m, lst;
char g[151][151];

int L[151], R[151];
int rec(int i, int j){

	if (i == lst){
		if (i % 2){
			return abs(j - L[i]);
		}
		else{
			return abs(j - R[i]);
		}
	}
	int ret = 0;
	if (i % 2){
		ret +=rec(i + 1, min(j, min(L[i], L[i + 1]))) + abs( min(j, min(L[i], L[i + 1])) - j) + 1;
	}
	else{
		ret +=rec(i + 1, max(j , max(R[i], R[i + 1]))) + abs(max( j ,max(R[i], R[i + 1])) - j) + 1;
	}
	return ret;
}
int main(){
	fast();
	memset(L, OO, sizeof L);
	memset(R, -1, sizeof R);
	cin >> n >> m;
	lst = -1;
	for (int i = 0; i < n; i++){
		bool f = 0;
		for (int j = 0; j < m; j++){
			cin >> g[i][j];
			if (!f && g[i][j] == 'W'){
				f = 1;
				L[i] = j;
			}
			(g[i][j] == 'W') ? R[i] = j : 0;
		}
		if (f == 1){
			lst = i;
		}
	}
	if (lst == -1){
		cout << 0 << endl;
	}
	else{
		cout << rec(0, 0) << endl;
	}
	return 0;
}
