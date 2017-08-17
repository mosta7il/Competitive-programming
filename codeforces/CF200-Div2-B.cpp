#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
bool p(int x){
	for (int j = 2; j < 25; j++){
		if (x % 2 == 0 && x != 2){
			return false;
		}
		if (x%j == 0 && x != j){
			return false;
		}
	}
	return true;

}
void main(){

	long double  sum = 0;
	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += ((double)a[i] / 100);
	}

	cout << fixed << setprecision(12) << ((sum / n) * 100);
}
