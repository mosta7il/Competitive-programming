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
#include<fstream>
#include<map>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
vector<int> a;
int main(){
	fast();
	int n, x;
	cin >> n >> x; int res = 0;
	 int ind = -1;
	 a.resize(n + 1, 1e9);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ind = (a[i] == x) ? i:ind;
	}
	int d = 0;
	if (ind == -1){
		a[n] = x;
		n++; res++;
		
	}

	sort(a.begin(),a.end());

	int med = floor((n + 1) / 2.00);
	if (x == a[med-1]){
		cout << res << endl;
	}
	else if(x > a[med-1]){

		for (int mid = 1; mid <= n; mid++){
			a.push_back(1e9);
			if (a[(int)floor((n + mid + 1) / 2.00) - 1] == x){
				cout << res + mid << endl;
				return 0;
			}
		}
	}
	else{
		for (int mid = 1; mid <= n; mid++){
			a.insert(a.begin() , 1);
			if (a[(int)floor((n + mid + 1) / 2.00) - 1] == x){
				cout << res + mid << endl;
				return 0;
			}
		}
	}
	
	return 0;
}
//mosta7il_
