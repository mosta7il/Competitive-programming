#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 5 * 100 * 1000+ 5;
int n;

string a[MAX];

bool cmp(string i, string j){

	string ij = i + j;
	string ji = j + i;
	if (ij < ji)
		return 1;
	return 0;
}


int main(){
	fast();
	
	while (cin>>n){
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);

		for (int i = 0; i < n; i++)
			cout << a[i];
		cout << endl;
	}
	return 0;
}
