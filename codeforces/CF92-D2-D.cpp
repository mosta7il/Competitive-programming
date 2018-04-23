#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e9+5;
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
int a[100 * 1000 + 1];
multiset<pair<int , int> >s;
int res[100 * 1000 + 1];
int main(){
	fast();
	
	cin >> n;
	for (int i = 0; i <= n; i++)
		res[i] = -2;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s.insert({ a[i], i });
	}
	
	for (int i = n; i >= 1; i--){

		multiset<pair<int, int> >::iterator it = s.lower_bound({ a[i],i });
		multiset<pair<int, int>>::iterator ii = it;
		if (res[i] == -2)
			res[i] = -1;
		if (it != s.end())
			it++;
		while (it != s.end()){
			res[(*(it)).second] = i - (*it).second -1;
			it++;
		}
		s.erase(ii, s.end());
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
