#include<iostream>
#include<cmath>
using namespace std;

int main(){

	long long s, l, sum = 0;
	cin >> s >> l;
	sum = s;
	for (int i = 1; sum <= l; i++){
		if (sum == l){
			cout << "YES";
			cout << endl << i - 1; return 0;
		}
		sum = pow((double)s, i + 1);
	}
	cout << "NO";
	return 0;
}
