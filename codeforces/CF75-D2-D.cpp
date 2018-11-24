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
const int MAX = 200 * 1000  + 1;

int n;
int m;
int tmp[5001];

struct small{
	long long best, sum;
	long long bestLeft, bestRight;
	bool haspos;
	int mxn;
}a[55];
int l;

int calc_best(){
	int mx = 0 , sum = 0;
	for (int i = 0; i < l; i++){
		sum += tmp[i];
		if (sum < 0){
			sum = 0;
		}
		mx = max(mx, sum);
	}
	return mx;
}
int calc_sum(){
	int sum = 0;
	for (int i = 0; i < l; i++)
		sum += tmp[i];
	return sum;
}
int calc_left(){
	int mx = 0, sum = 0;
	for (int i = 0; i < l; i++){
		sum += tmp[i];
		mx = max(mx, sum);
	}
	return mx;
}
int calc_right(){
	int mx = 0, sum = 0;
	for (int i = l - 1; i >= 0; i--){
		sum += tmp[i];
		mx = max(mx, sum);
	}
	return mx;
}
bool calc_pos(){
	bool ret = 0;
	for (int i = 0; i < l; i++){
		ret |= (tmp[i] >= 0);
	}
	return ret;
}
int calc_maxn(){
	int mx = tmp[0];

	for (int i = 1; i < l; i++){
		mx = max(tmp[i], mx);
	}
	return mx;
}
int main(){
	fast();
	
	cin >> n>>m;

	for (int i = 0; i < n; i++){
		cin >> l;

		for (int idx = 0; idx < l; idx++){
			cin >> tmp[idx];
		}
		a[i].best = calc_best();
		a[i].sum = calc_sum();
		a[i].bestLeft = calc_left();
		a[i].bestRight = calc_right();
		a[i].haspos = calc_pos();
		a[i].mxn = calc_maxn();
	}
	small tot;
	for (int i = 0; i < m; i++){
		int u; cin >> u; u--;
		if (!i)
			tot = a[u];
		else{
			tot.best = max(tot.best,
				max(a[u].best, tot.bestRight + a[u].bestLeft));
			tot.bestRight = max(a[u].bestRight, a[u].sum + tot.bestRight);
			tot.bestLeft = max(tot.bestLeft, tot.sum + a[u].bestRight);
			tot.sum += a[u].sum;
			tot.haspos |= a[u].haspos;
			tot.mxn = max(tot.mxn, a[u].mxn);
		}
	}
	if (tot.haspos){
		cout << tot.best << endl;
	}
	else cout << tot.mxn << endl;
	return 0;
}
