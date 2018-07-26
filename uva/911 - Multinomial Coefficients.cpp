#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e9;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long long MAX = 20 *1000 * 1000 + 1;

int n, k;
map<int , int> a;
int c[101];
map<int , int> pf(int x){
	map<int , int>ret;
	for (long long i = 2; i*i <= x; i++){
		while (x%i == 0){
			ret[i]++;
			x /= i;
		}
	}
	
	if (x > 1)ret[x]++;
	return ret;
}

long long pwr(long long a, long long b){

	if (b == 0)return 1;
	if (b == 1)return a;

	long long tt = pwr(a, b / 2);
	return tt * tt * pwr(a, b % 2);
}
int main(){
	fast();
	while (cin >> n){
		cin >> k;
		a.clear();
		for (int i = 0; i < k; i++){
			cin >> c[i];
		}

		for (int i = 2; i <= n; i++){
			map<int, int>res = pf(i);
			for (auto x : res){
				a[x.first] += x.second;
			}
		}
		
		for (int i = 0; i < k; i++){

			for (int j = 2; j <= c[i]; j++){
				map<int, int> res = pf(j);
				for (auto x : res){
					a[x.first] -= x.second;
				}
			}
		}
		long long ans = 1;
		for (auto x : a){
				ans *= pwr(x.first, x.second);
		}
		cout << ans << endl;
	}
	
	return 0;
}
