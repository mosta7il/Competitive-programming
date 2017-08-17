#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main(){
	int n, t = 0;;
	cin >> n;
	vector<int>v;
	int a[1000][2];
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i < n; i++){
		t += a[i][1]-a[i][0];
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	cout << v.at(v.size() - 1);
}
