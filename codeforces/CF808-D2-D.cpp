#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
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
int n;
long long a[1000 * 100 + 1];
multiset<long long>pre;
long long sum = 0, pres = 0;
int main(){
	fast();
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum = sum + a[i];
	}
	if (n == 1 || sum % 2){
		return cout << "NO\n", 0;
	}
	for (int i = 0; i < n; i++){
		pre.insert(a[i]);
		pres = pres + a[i];
		if (pres == sum / 2){
			cout << "YES\n";
			return 0;
		}
		else if (pres > sum / 2){
			if (pre.find(pres - (sum / 2)) != pre.end()){
				cout << "YES\n";
				return 0;
			}
		}
	}
	pres = 0; pre.clear();
	for (int i = n - 1; i >= 0; i--){
		pre.insert(a[i]);
		pres = pres + a[i];
		if (pres == sum / 2){
			cout << "YES\n";
			return 0;
		}
		else if (pres > sum / 2){
			if (pre.find(pres - (sum / 2)) != pre.end()){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}
