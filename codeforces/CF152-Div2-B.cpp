#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<limits.h>
#include<cmath>
using namespace std;
struct t{
	int x, y;
};
int n, m;
bool valid(int x, int y){
	if (x > n || y > m)
		return 0;
	if (x > 0 && y > 0)
		return 1;
	return 0;
}
int main(){
	
	int x, y;
	int k;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	//cin >> n >> m >> x >> y >> k;
	t *a = new t[k];
	for (int i = 0; i < k; i++){
		/*cin >> a[i].x>>a[i].y;*/
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	long long cnt = 0;
	for (int i = 0; i < k; i++){
		long long nx, ny;
		if (a[i].x >= 0){
			nx = n - x;
		}
		else{
			nx = x - 1;
		}
		if (a[i].y >= 0){
			ny = m - y;
		}
		else{
			ny = y - 1;
		}
		if (a[i].x != 0){
			nx = nx /abs( a[i].x);
		}
		else{
			nx = INT_MAX;
		}
		if (a[i].y != 0){
			ny = ny / abs(a[i].y);
		}
		else{
			ny = INT_MAX;
		}
		long long m = min(nx, ny);
		x = x + m * a[i].x;
		y = y + m * a[i].y;
		cnt += m;
	}
	cout << cnt << endl;
	return 0;
}
