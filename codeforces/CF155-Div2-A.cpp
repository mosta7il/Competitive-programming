#include<iostream>
#include<vector>
using namespace std;

void main(){
	int n ,c1=0,c2=0,c3=0;
	cin >> n;
	int *a = new int[n];
	bool t = false;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i < n; i++){
		c1 = 0;
		c2 = 0;
		for (int j = i - 1; j >= 0; j--){
			if (a[i] >a[j]){
				c1++;
			}
			else if (a[i] < a[j]){
				c2++;
			}
		}
		if (c1 == i || c2 == i){
			c3++;
		}
	}

	cout << c3;

}
