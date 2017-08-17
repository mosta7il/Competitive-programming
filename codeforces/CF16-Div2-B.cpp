#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int> i, pair<int, int> j){
	if (i.second > j.second)
		return 1;
	return 0;
}
int main(){

	int n, m;
	cin >> n >> m;
	pair<int, int> *a = new pair<int, int>[m];
	for (int i = 0; i < m; cin >> a[i].first >> a[i].second, i++);
	sort(a, a + m, cmp);

	int res = 0;
	for (int i = 0; i < m && n > 0; i++){
		if (a[i].first <= n){
			res += a[i].first * a[i].second;
			n -= a[i].first;
		}
		else{
			res += n * a[i].second;
			n = 0;
		}
	}

	cout << res << endl;
	return 0;
}
