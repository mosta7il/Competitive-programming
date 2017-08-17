#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int n, k, cn = 0, ind = 0 , mn = INT_MAX ;
	long long sum = 0;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] < 0){
			cn++;
			
		}
		sum += abs(a[i]);
		if (mn > abs(a[i])){
			mn = abs(a[i]);
			ind = i;
		}
	}

	if (cn == 0 && (k % 2 == 0)){
		cout << sum << endl;
	}
	else if (cn == 0 && (k % 2 != 0))
	{
		cout << sum - (a[0]*2) << endl;
	}
	else{
		if (k < cn){
			int w = k;
			for (int i = w; i < cn; i++ ){
				sum += (a[i]* 2) ;
			}

			cout << sum << endl;
		}
		else if(k == cn){
			cout << sum << endl;
		}
		else{
			k = k - cn;
			if (k % 2 == 1){
				
					cout << sum - (abs(a[ind])*2) << endl;
			}
			else{
				cout << sum << endl;
			}
		}
	}
	return 0;
}
