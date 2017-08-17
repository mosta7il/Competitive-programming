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


int main(){
	

	int n;
	cin >> n;
	int s1 = 0, s2 = 0;
	stringstream ss;
	pair<int, int> *a = new pair<int , int>[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		if (abs(s1 + a[i].first - s2) <= 500){
			s1 += a[i].first;
			ss << 'A';
		}
		else if (abs(s2 + a[i].second - s1) <= 500){
			s2 += a[i].second;
			ss << 'G';
		}
		else{
			s1 += a[i].first;
			ss << 'A';
		}
	}

	cout << ss.str() << endl;

	return 0;
}
// mosta7il_
