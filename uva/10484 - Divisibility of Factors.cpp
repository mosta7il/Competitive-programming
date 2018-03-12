#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("E:\\Programming\\Problem Solving\\inout files\\input.txt", "r", stdin);
	freopen("E:\\Programming\\Problem Solving\\inout files\\output.txt", "w", stdout);
#endif
}
int n, m;
int pn[101], pm[101];
bool f = 0;
void fun(int* a , int x){
	for (int i = 2; i * i <= x; i++){
		while (x % i == 0){
		  if (i<=100)
			a[i]++;
		  else {
			  f = 1;
			  return;
		  }
			x /= i;
		}
	}
	if (x > 1){
		if (x <= 100)
		a[x]++;
		else f = 1;
	}
}
int main(){
	fast();
	while (cin >> n >> m&& (abs(n)>0||abs(m)>0)){
		n = abs(n);
		m = abs(m);
		f = 0;
		memset(pn, 0, sizeof pn);
		memset(pm, 0, sizeof pm);
		for (int i = 2; i <= n;i++)
			fun(pn, i); 
		f = 0;
		fun(pm, m);
		if (f){
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < 101; i++){
			if (pn[i] < pm[i]){
				cout << 0 << endl;
				f = 1;
				break;
			}
		}
		if (f)
			continue;
		long long rs = 1;
		for (int i = 0; i < 101; i++){
			rs *= (pn[i] - pm[i] + 1);
		}
		cout << rs << endl;
	}
	return 0;
}
