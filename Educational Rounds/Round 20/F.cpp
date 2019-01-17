/*


*/

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
#define EPS 1e-12
#define MLOG 20
#define MAX  100  * 1000+5
const int mod = 1e9+7;

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
int n;
int a[MAX], cnt[MAX], pwr[MAX] , mo[MAX];
ll fun(int x){

 return  (pwr[x] - 1) % mod;
}
int main(){
	fast();
	pwr[0] = 1;
	for (int i = 1; i < MAX; i++)
		pwr[i] = (pwr[i - 1] * 2) % mod;
	mo[1] = 1;
	for (int i = 2; i < MAX; i++){
		int t = i, f = 0;
		mo[i] = 1;
		for (int j = 2; 1ll * j * j <= t; j++){
			if (t%j == 0){
				t /= j;
				f++;
				if (t%j == 0) {
					mo[i] = 0; break;
				}
			}
		}
		if (t)f++;
		mo[i] = (f % 2) ? -mo[i] : mo[i];
	}

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		for (int j = 1; 1ll * j * j <= a[i]; j++){
			if (a[i] % j == 0){
				cnt[j]++;
				if (1ll * j * j != a[i])
					cnt[a[i] / j]++;
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i < MAX; i++){
		ans += (mo[i] * fun(cnt[i])) % mod;
		ans %= mod;
		ans += mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
} 
