#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int n, t, sum = 0, cnt = 0, maxx = 0 , r = 0;
	cin >> n >> t;
	int *a = new int[n];
	for (int i = 0; i < n; cin >> a[i++]);
	int j = 0;
	for (int i = 0; i < n; i++){
		while (r < n && sum + a[r] <= t){
			sum += a[r];
			r++;
		}
		maxx = max(maxx, r - i);
		sum -= a[i];
	}
	cout << maxx << endl;
	return 0;
}
