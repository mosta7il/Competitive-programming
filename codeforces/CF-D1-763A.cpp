#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h> 
using namespace std;

const long long OO = 1000;
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
const int MAX = 1e5+1;

int n, m;
int c[MAX];
pair<int, int> edge[MAX];

bool check(int src){

	for (int i = 0; i < m; i++){
		if (src == edge[i].first || src == edge[i].second)
			continue;
		if (c[edge[i].first] != c[edge[i].second])
			return 0;
	}
	return 1;
}
int main(){
	fast();
	cin >> n;
	m = n - 1;
	for (int i = 0; i < m; i++){
		cin >> edge[i].first >> edge[i].second;
	}
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	bool f = 0;
	int src1, src2;
	for (int i = 0; i < m; i++){
		if (c[edge[i].first] != c[edge[i].second]){
			f = 1;
			src1 = edge[i].first;
			src2 = edge[i].second;
			break;
		}
	}
	if (!f){
		cout << "YES\n";
		cout << 1 << endl;
		return 0;
	}
	if (check(src1)){
		cout << "YES\n";
		cout <<src1<< endl;
	}
	else if (check(src2)){
		cout << "YES\n";
		cout << src2 << endl;
	}
	else{
		cout << "NO\n";
	}

	return 0;
}
