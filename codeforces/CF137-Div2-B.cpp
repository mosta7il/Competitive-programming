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

using namespace std;
bool a[5001];

int main(){
	int n;
	cin >> n;
	 int w = 0;
	
	for (int i = 0; i < n; i++){
		cin >> w;
		a[w - 1] = 1;
	}
	int res = 0;
	for (int i = 0; i < n; i++){
		res += (!a[i]);
	}
	cout << res << endl;
	return 0;
}
