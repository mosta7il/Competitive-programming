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
int n, x, y;
string a[2*1000 * 1000 + 3];

int main(){
	fast();
	cin >> n >> x >> y;
	int c = 0;
	for (int i = 1 , j = 1;c<= x+y;){
		if ((i * 1.0 / x) < (j*1.0 / y)){
			a[c] = "Vanya";
			i++;
		}
		else if ((i * 1.0 / x) > (j*1.0 / y)){
			a[c] = "Vova";
			j++;
		}
		else {
			a[c++]="Both";
			a[c] = "Both";
			i++; j++;
		}
		c++;
	}
	int w;
	c--;
	for (int i = 0; i < n; i++){
		cin >> w;
		w--;
		w %= (c);
		cout << a[w] << endl;
	}

	return 0;
}
