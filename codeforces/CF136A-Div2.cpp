#include<iostream>
using namespace std;

void main(){
	int n = 0;
	cin >> n;
	int *a = new int [n], *b = new int [n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < n; j++){
			if (a[j] == i){
				b[i - 1] = j + 1;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout<< b[i]<<" ";
	}
}
