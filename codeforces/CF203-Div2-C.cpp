#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<queue>
#include<map>
#include<fstream>


using namespace std;

int n, d, a, b;
bool cmp( pair<int, long long> i, pair<int, long long> j){
	if (i.second< j.second)
		return 1;
	return 0;
}
int main(){
	ifstream fin("input.in");
	ofstream fout("output.out");
	cin >> n >> d >> a >> b;
	pair< int, long long> *q = new pair< int, long long>[n];
	for (int i = 0; i < n; i++){
		long long x, y;
		q[i].first = i + 1;
		cin >>x >> y;
		q[i].second = a *x + y * b;
	}
	sort(q, q + n, cmp);
	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++){
		if (q[i].second <= d){
			v.push_back(q[i].first);
			d -= q[i].second;
		}
		else{
			break;
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
// mosta7il_
