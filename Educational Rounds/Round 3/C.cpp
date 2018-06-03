#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1 , 1 , 1 , -1 , -1};
int dy[] = { 1, -1, 0, 0 ,1 ,-1 , 1 , -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n;
int a[100 * 1000 + 1], b[100 * 1000 + 1];;
int sum;
int main(){
	fast();
	cin >> n;
	int x;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	if (n == 1)
		return cout << 0 << endl, 0;
	int cnt = 0;
	sort(a, a + n);
	int div = sum / n;
	int rem = sum %n;
	for (int i = 0; i < n; i++){
		b[i] = div;
	}
	for (int i = n - 1; i >= 0; i--){
		if (rem){
			rem--;
			b[i]++;
		}
		cnt += max(0, b[i] - a[i]);
	}
	cout << cnt << endl;
	return 0;
}
