#include<iostream>
using namespace std;

void main(){
	int n;
	cin >> n;
	int a[7];
	for (int w= 0; w < 7; w++){
		cin >> a[w];
	}

	int i = -1 , sum =0;
	while (sum < n){
		i = (i + 1) % 7;
		sum += a[i];
		
	}
	cout << i + 1;
}
