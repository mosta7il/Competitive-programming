#include<iostream>
using namespace std;
struct t{
	int h;
	int i;
};
void main(){
	t min, max;
	min.h = 101;
	max.h = 0;
	min.i = -1;
	max.i = -1;
	int n = 0;
	cin >> n;
	int a ;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (a > max.h){
			max.h = a;
			max.i = i+1;
		}
		if (a <= min.h){
			min.h = a;
			min.i = i+1;
		}
	}
	if (min.i < max.i){
		cout << (max.i - 1) + (n - min.i) - 1;
	}
	else{
		cout << (max.i - 1) + (n - min.i);
	}
}
