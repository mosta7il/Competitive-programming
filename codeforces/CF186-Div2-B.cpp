#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;double t1, t2, k;
int a[1001], b[1001];
pair<int, double> c[1001];
bool cmp(pair<int, double> i, pair<int, double>j){
	if (i.second > j.second)return 1;
	if (i.second == j.second&&i.first < j.first)return 1;
	return 0;
}
int main(){
	fast();
	cin >> n >> t1 >> t2 >> k;
	for (int i = 0; i < n; i++)cin >> a[i]>>b[i];
	
	for (int i = 0; i < n; i++){

		c[i].first = i + 1;
		double c1 = (t1 * a[i] * (1.0 - (k / 100))) + (t2 * b[i]);
		double c2 = (t1 * b[i] * (1.0 - (k / 100))) + (t2*a[i]);
		c[i].second = max(c1, c2);;
	}
	sort(c, c + n, cmp);
	for (int i = 0; i < n; i++){
		cout << c[i].first << " " << fixed << setprecision(2) << c[i].second << endl;
	}
	return 0;
}
//mosta7il_
